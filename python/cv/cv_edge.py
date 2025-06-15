#!/usr/local/bin/env python3
# encoding=utf-8

import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def edge_img(image : cv.Mat):
    edges = cv.Canny(image, 100, 700)

    fig, axs = plt.subplots(1, 2, figsize=(7, 4))
    axs[0].imshow(image), axs[0].set_title('Original Image')
    axs[1].imshow(edges), axs[1].set_title('Image Edges')

    for ax in axs:
        ax.set_xticks([]), ax.set_yticks([])

    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    image = cv.imread('F:/004.JPG', cv.IMREAD_COLOR_RGB)
    edge_img(image)
