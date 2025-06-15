#!/usr/local/bin/env python3
# encoding=utf-8

import cv2
import matplotlib.pyplot as plt
import cv_util

img = cv_util.read_example_img()
layer = img.copy()
for i in range(4):
    plt.subplot(2,2, i+1)
    
    layer = cv2.pyrDown(layer)
    plt.imshow(layer)

plt.show()


