import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense
from tensorflow.keras.utils import to_categorical
import numpy as np
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
num_classes = 10
img_rows, img_cols = 28, 28
x_train = x_train.reshape(x_train.shape[0], img_rows, img_cols, 1)
x_test = x_test.reshape(x_test.shape[0], img_rows, img_cols, 1)
input_shape = (img_rows, img_cols, 1)
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0
y_train_encoded = to_categorical(y_train, num_classes)
y_test_encoded = to_categorical(y_test, num_classes)
model = Sequential([
    Conv2D(6, kernel_size=(5, 5), activation='relu', input_shape=input_shape, padding='same'),
    MaxPooling2D(pool_size=(2, 2)),
    Conv2D(16, kernel_size=(5, 5), activation='relu'),
    MaxPooling2D(pool_size=(2, 2)),
    Flatten(),
    Dense(120, activation='relu'),
    Dense(84, activation='relu'),
    Dense(num_classes, activation='softmax')
])
model.summary()
model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)
print("\n--- 开始训练 LeNet-5 模型 ---")
history = model.fit(
    x_train, 
    y_train_encoded, 
    epochs=10,        
    batch_size=128,    
    validation_split=0.1
)
print("\n--- 在测试集上评估模型 ---")
loss, accuracy = model.evaluate(x_test, y_test_encoded, verbose=2)
print(f"\n测试集准确率 (Test Accuracy): {accuracy:.4f}")