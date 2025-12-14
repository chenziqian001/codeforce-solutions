import tensorflow as tf
import numpy as np

# 1. 数据加载与预处理
fashion_mnist = tf.keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

train_images = train_images / 255.0
test_images = test_images / 255.0
def create_fcn_model():
    model = tf.keras.Sequential([
        # 展平层 (Flatten)：将 28x28 图像转换为 784 维向量
        tf.keras.layers.Flatten(input_shape=(28, 28), name='Flatten_Input'),
        
        # 隐藏层 1：全连接层
        tf.keras.layers.Dense(128, activation='relu', name='Dense_Hidden_1'),
        
        # 隐藏层 2：全连接层
        tf.keras.layers.Dense(64, activation='relu', name='Dense_Hidden_2'),
        
        # 输出层：10个类别
        tf.keras.layers.Dense(10, activation='softmax', name='Dense_Output')
    ])
    return model

fcn_model = create_fcn_model()

# 2. 编译模型
fcn_model.compile(optimizer='adam',
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])

# 3. 输出模型结构和每层输出形状 (用于实验报告截图)
print("="*60)
print("== 实验一：全连接网络 (FCN) 模型结构与输出形状 ==")
print("="*60)
fcn_model.summary() 
print("="*60)

# 4. 训练模型
print("\n开始训练 FCN 模型...")
fcn_model.fit(train_images, train_labels, epochs=5, verbose=1)

# 5. 评估模型
loss, acc = fcn_model.evaluate(test_images, test_labels, verbose=2)
print(f"\nFCN 模型测试集准确率: {acc:.4f}")