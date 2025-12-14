import tensorflow as tf
from tensorflow.keras import layers, models, Input
import matplotlib.pyplot as plt
import numpy as np

# ==========================================
# 1. 数据准备
# ==========================================
def load_data():
    print("正在加载 Fashion-MNIST 数据集...")
    (x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
    
    # 归一化并增加通道维度 (28, 28) -> (28, 28, 1)
    x_train = x_train.reshape(-1, 28, 28, 1).astype('float32') / 255.0
    x_test = x_test.reshape(-1, 28, 28, 1).astype('float32') / 255.0
    
    return (x_train, y_train), (x_test, y_test)

# 辅助函数：定义带BN的卷积块 (Conv -> BN -> ReLU)
# 注意：使用BN时，卷积层通常不需要偏置(use_bias=False)
def conv_bn_relu(x, filters, kernel_size, strides=1, padding='same'):
    x = layers.Conv2D(filters, kernel_size, strides=strides, padding=padding, use_bias=False)(x)
    x = layers.BatchNormalization()(x) # 添加批量归一化
    x = layers.Activation('relu')(x)
    return x

# ==========================================
# 2. NiN (Network in Network) 模型搭建
# ==========================================
def create_nin_with_bn(input_shape, num_classes):
    """
    NiN的核心思想：使用1x1卷积代替全连接层，最后使用全局平均池化。
    这里针对28x28输入进行了适配。
    """
    inputs = Input(shape=input_shape)
    
    # NiN Block 1
    # 原始论文由大核开始，这里适配28x28改为5x5
    x = conv_bn_relu(inputs, 96, kernel_size=5, padding='same')
    x = conv_bn_relu(x, 96, kernel_size=1) # 1x1 Conv 充当全连接
    x = conv_bn_relu(x, 96, kernel_size=1)
    x = layers.MaxPooling2D(pool_size=3, strides=2, padding='same')(x)
    x = layers.Dropout(0.5)(x)

    # NiN Block 2
    x = conv_bn_relu(x, 256, kernel_size=5, padding='same')
    x = conv_bn_relu(x, 256, kernel_size=1)
    x = conv_bn_relu(x, 256, kernel_size=1)
    x = layers.MaxPooling2D(pool_size=3, strides=2, padding='same')(x)
    x = layers.Dropout(0.5)(x)

    # NiN Block 3
    x = conv_bn_relu(x, 384, kernel_size=3, padding='same')
    x = conv_bn_relu(x, 384, kernel_size=1)
    x = conv_bn_relu(x, 384, kernel_size=1)
    x = layers.MaxPooling2D(pool_size=3, strides=2, padding='same')(x)
    x = layers.Dropout(0.5)(x)

    # Output Block
    # 最后一个块的通道数等于类别数
    x = conv_bn_relu(x, num_classes, kernel_size=3, padding='same') # 此处也可以用1x1
    
    # Global Average Pooling 替代 Flatten + Dense
    x = layers.GlobalAveragePooling2D()(x)
    outputs = layers.Activation('softmax')(x)

    return models.Model(inputs, outputs, name="NiN_with_BN")

# ==========================================
# 3. GoogLeNet (Inception V1) 模型搭建
# ==========================================
def inception_module(x, filters):
    """
    Inception 模块：并行使用不同尺寸的卷积核
    filters: 包含4个分支通道数的列表/元组
    格式: (f_1x1, f_3x3_reduce, f_3x3, f_5x5_reduce, f_5x5, f_pool_proj)
    """
    (f_1x1, f_3x3_r, f_3x3, f_5x5_r, f_5x5, f_pp) = filters

    # 分支1: 1x1 卷积
    branch1 = conv_bn_relu(x, f_1x1, 1)

    # 分支2: 1x1 降维 -> 3x3 卷积
    branch2 = conv_bn_relu(x, f_3x3_r, 1)
    branch2 = conv_bn_relu(branch2, f_3x3, 3)

    # 分支3: 1x1 降维 -> 5x5 卷积
    branch3 = conv_bn_relu(x, f_5x5_r, 1)
    branch3 = conv_bn_relu(branch3, f_5x5, 5)

    # 分支4: 3x3 最大池化 -> 1x1 卷积
    branch4 = layers.MaxPooling2D(3, strides=1, padding='same')(x)
    branch4 = conv_bn_relu(branch4, f_pp, 1)

    # 拼接
    return layers.Concatenate(axis=-1)([branch1, branch2, branch3, branch4])

def create_googlenet_with_bn(input_shape, num_classes):
    """
    精简版 GoogLeNet，适配 Fashion-MNIST
    """
    inputs = Input(shape=input_shape)

    # 初始层 Stem
    x = conv_bn_relu(inputs, 64, 7, strides=2, padding='same')
    x = layers.MaxPooling2D(3, strides=2, padding='same')(x)

    x = conv_bn_relu(x, 64, 1)
    x = conv_bn_relu(x, 192, 3, padding='same')
    x = layers.MaxPooling2D(3, strides=2, padding='same')(x)

    # Inception 模块块 (这里仅使用了两个模块以减少参数量，适合实验)
    # filters格式: (1x1, 3x3_red, 3x3, 5x5_red, 5x5, pool_proj)
    x = inception_module(x, (64, 96, 128, 16, 32, 32))
    x = inception_module(x, (128, 128, 192, 32, 96, 64))

    # 输出层
    x = layers.GlobalAveragePooling2D()(x)
    x = layers.Dropout(0.4)(x)
    outputs = layers.Dense(num_classes, activation='softmax')(x)

    return models.Model(inputs, outputs, name="GoogLeNet_with_BN")

# ==========================================
# 4. 训练与评估通用函数
# ==========================================
def train_model(model, x_train, y_train, x_test, y_test, epochs=5, batch_size=128):
    model.compile(optimizer='adam',
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])
    
    print(f"\n开始训练模型: {model.name}")
    model.summary()
    
    history = model.fit(x_train, y_train, 
                        epochs=epochs, 
                        batch_size=batch_size, 
                        validation_data=(x_test, y_test))
    return history

# ==========================================
# 5. 主程序执行
# ==========================================
if __name__ == "__main__":
    # 加载数据
    (x_train, y_train), (x_test, y_test) = load_data()
    input_shape = (28, 28, 1)
    num_classes = 10

    # --- 实验 1: 训练 NiN ---
    nin_model = create_nin_with_bn(input_shape, num_classes)
    train_model(nin_model, x_train, y_train, x_test, y_test, epochs=5)

    print("\n" + "="*50 + "\n")

    # --- 实验 2: 训练 GoogLeNet ---
    googlenet_model = create_googlenet_with_bn(input_shape, num_classes)
    train_model(googlenet_model, x_train, y_train, x_test, y_test, epochs=5)

    print("\n实验结束。")