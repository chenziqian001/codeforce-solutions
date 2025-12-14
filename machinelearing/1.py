import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten
from tensorflow.keras.utils import to_categorical
import numpy as np
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
num_classes = 10
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0
y_train_encoded = to_categorical(y_train, num_classes=num_classes)
y_test_encoded = to_categorical(y_test, num_classes=num_classes)
model = Sequential([
    # 将 28x28 图像展平为 784 维向量
    Flatten(input_shape=(28, 28)), 
    # 第一个隐藏层，128 个神经元，ReLU 激活
    Dense(128, activation='relu'),
    # 第二个隐藏层，64 个神经元，ReLU 激活
    Dense(64, activation='relu'),
    # 输出层，10 个神经元，Softmax 激活（多分类概率）
    Dense(num_classes, activation='softmax')
])
model.summary()
model.compile(
    optimizer='adam',
    # 标签已独热编码，使用 categorical_crossentropy
    loss='categorical_crossentropy',
    metrics=['accuracy']
)
print("\n--- 开始训练模型 ---")
history = model.fit(
    x_train, 
    y_train_encoded, 
    epochs=10,        
    batch_size=32,    
    validation_split=0.1
)
print("\n--- 在测试集上评估模型 ---")
loss, accuracy = model.evaluate(x_test, y_test_encoded, verbose=2)

print(f"\n测试集准确率 (Test Accuracy): {accuracy:.4f}")