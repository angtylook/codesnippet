import cv2
from matplotlib import pyplot as plt
import cv_util

img = cv_util.read_example_img()

#
#h：决定滤波器强度的参数。较高的 h 值可以更好地去除噪声，但也同时去除图像细节。（10 还可以）
#hForColorComponents：与 h 相同，但仅用于彩色图像。（通常与 h 相同）
#templateWindowSize：应为奇数。（推荐 7）
#searchWindowSize：应为奇数。（推荐 21）
#
dst = cv2.fastNlMeansDenoisingColored(img, None, 5, 5, 7, 15)
plt.subplot(1, 2, 1)
plt.imshow(img)
plt.subplot(1, 2, 2)
plt.imshow(dst)
plt.show()