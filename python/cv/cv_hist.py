#!/usr/local/bin/env python3
# encoding=utf-8

import cv2
import matplotlib.pyplot as plt
import cv_util

img = cv_util.read_example_img()
hist = cv2.calcHist([img], [0], None, [256], [0,256])

plt.subplot(1,2,1)
plt.imshow(img)

plt.subplot(1,2,2)
plt.plot(hist)

plt.show()
