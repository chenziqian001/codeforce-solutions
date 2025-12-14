import tensorflow as tf
from tensorflow.keras.layers import Dense, GlobalAveragePooling2D, Conv2D, Concatenate, BatchNormalization, Activation
from tensorflow.keras.models import Model
from tensorflow.keras.datasets import fashion_mnist
import matplotlib.pyplot as plt
import numpy as np


(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()
train_images = train_images.astype('float32') / 255.0
test_images = test_images.astype('float32') / 255.0


train_images = np.expand_dims(train_images, -1)
test_images = np.expand_dims(test_images, -1)


def conv_block(x, growth_rate, name):
    x1 = BatchNormalization(name=name + '_bn_1')(x)
    x1 = Activation('relu', name=name + '_relu_1')(x1)
    
    x1 = Conv2D(growth_rate, (3, 3), padding='same', use_bias=False, name=name + '_conv_1')(x1)
    x = Concatenate(name=name + '_concat')([x, x1])
    return x

def dense_block(x, blocks, growth_rate, name):
    for i in range(blocks):
        x = conv_block(x, growth_rate, name=name + '_block_' + str(i + 1))
    return x


input_shape = train_images.shape[1:]
img_input = tf.keras.Input(shape=input_shape)


x = Conv2D(16, (3, 3), strides=(1, 1), padding='same', use_bias=False, name='conv1')(img_input)
x = BatchNormalization(name='bn_conv1')(x)
x = Activation('relu', name='relu_conv1')(x)


x = dense_block(x, blocks=2, growth_rate=8, name='db_1') # 仅2个block，growth_rate=8


x = GlobalAveragePooling2D(name='avg_pool')(x)


x = Dense(10, activation='softmax', name='predictions')(x)

model = Model(img_input, x, name='densenet_fashion_mnist_simple')


model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])


history = model.fit(train_images, train_labels, epochs=5,
                    validation_data=(test_images, test_labels),
                    verbose=0)


plt.figure(figsize=(12, 4))
plt.subplot(1, 2, 1)
plt.plot(history.history['accuracy'], label='Accuracy')
plt.plot(history.history['val_accuracy'], label='Val Accuracy')
plt.title('Model Accuracy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(history.history['loss'], label='Loss')
plt.plot(history.history['val_loss'], label='Val Loss')
plt.title('Model Loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend()
plt.show()