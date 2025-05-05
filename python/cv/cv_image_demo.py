#!/usr/local/bin/env python3
# encoding=utf-8

import cv2

image = cv2.imread("D:/study/road.jpg")

# row, cols, channel
h, w = image.shape[:2]
print(f'Height={h}, Width={w}')

(B, G, R) = image[100,100]

print(f"R={R}, G={G}, B={B}")

B = image[100,100,0]
print(f"B={B}")

roi = image[100:500, 200:700]
cv2.imshow("ROI", roi)
cv2.waitKey(0)

ratio = 800 / w
dim =(800, int(h*ratio))

resize_aspect = cv2.resize(image, dim)
cv2.imshow("Resized Image", resize_aspect)
cv2.waitKey(0)




