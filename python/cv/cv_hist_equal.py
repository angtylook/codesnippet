#!/usr/local/bin/env python3
# encoding=utf-8

import cv2
import matplotlib.pyplot as plt
import cv_util

img = cv_util.read_example_img_gray()
equ = cv2.equalizeHist(img)

plt.subplot(1, 2, 1)
plt.imshow(img, cmap='gray', vmin=0, vmax=255)
plt.subplot(1, 2, 2)
plt.imshow(equ, cmap='gray', vmin=0, vmax=255)
plt.show()
