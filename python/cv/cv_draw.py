#!/usr/local/bin/env python3
# encoding=utf-8

import cv2 as cv
import numpy as np

# opencv, color default use BGR

img = np.zeros((512,512,3), np.uint8)
cv.line(img, (0,0), (511,511), (255,0,0), 5)
cv.rectangle(img, (384, 0), (510,128), (0,255,0), 3)
cv.circle(img, (447,63), 63, (0,0, 255), -1)
cv.ellipse(img, (256,256),(100,50), 0, 0, 180, 255, -1)
'''
reshape((-1, 1, 2)) 的含义:

reshape() 方法用于改变 NumPy 数组的形状，而不改变其数据内容。(-1, 1, 2) 这个元组作为 reshape() 的参数，其每个元素的含义如下：

-1: 这是一个特殊的占位符。它告诉 NumPy 自动计算这一维度的尺寸，以确保数组中的元素总数保持不变。在你的例子中，原始数组有 4 * 2 = 8 个元素。如果我们将其他维度固定为 1 和 2，那么 NumPy 会计算出第一维应该是 8 / (1 * 2) = 4。所以，-1 在这里会被自动推断为 4。

1: 这表示新的数组的第二个维度的尺寸是 1。

2: 这表示新的数组的第三个维度的尺寸是 2。这与原始数组中每个点有两个坐标 (x, y) 相对应。

因此，pts.reshape((-1, 1, 2)) 的作用是将形状为 (4, 2) 的二维数组 pts 转换为形状为 (4, 1, 2) 的三维数组。

输出会是这样的：

[[[10 5]]

 [[20 30]]

 [[70 20]]

 [[50 10]]]
解释转换后的形状 (4, 1, 2):

4: 仍然有 4 个“外层”元素，对应于原始的 4 个点。
1: 每个“外层”元素现在包含一个长度为 1 的子数组。
2: 这个长度为 1 的子数组内部包含一个长度为 2 的数组，代表点的 [x, y] 坐标。

在 OpenCV 中，很多绘制多边形或轮廓的函数（例如 cv2.polylines(), cv2.drawContours()）期望输入的点坐标数组具有特定的形状，通常是 (n_contours, n_points_in_contour, 1, 2) 或 (n_points, 1, 2)。

n_contours: 轮廓的数量。
n_points_in_contour: 每个轮廓包含的点数。
1: 表示这是一个包含单个点的“向量”。
2: 表示每个点有 2 个坐标 (x, y)。
将 pts reshape 成 ((-1, 1, 2)) 的形状，就是将每个单独的点 [x, y] 封装在一个额外的维度中，使其符合 OpenCV 函数的输入要求，将每个点视为一个独立的、包含一个点的轮廓。

'''
pts = np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)
pts = pts.reshape((-1,1,2))
cv.polylines(img, [pts], True, (0,255,255))
font = cv.FONT_HERSHEY_SIMPLEX
cv.putText(img, "OpenCV", (10,500), font, 4, (255,255,255), 2, cv.LINE_AA)

cv.imshow("draw", img)
cv.waitKey(0)


