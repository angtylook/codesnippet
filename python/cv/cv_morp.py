#!/usr/local/bin/env python3
# encoding=utf-8

import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def morp_img(image : cv.Mat):
    image_gray = cv.cvtColor(image, cv.COLOR_RGB2GRAY)
    kernel = np.ones((3,3), np.uint8)
    # Expands object boundaries
    dilated = cv.dilate(image_gray, kernel, iterations=2)
    # Shrinks object boundaries.
    eroded = cv.erode(image_gray, kernel, iterations=2)
    # Removes small noise.
    opening = cv.morphologyEx(image_gray, cv.MORPH_OPEN, kernel)
    # Fills small holes
    closing = cv.morphologyEx(image_gray, cv.MORPH_CLOSE, kernel)

    fig, axs = plt.subplots(2,2, figsize=(7,7))
    axs[0, 0].imshow(dilated, cmap="Greys")
    axs[0, 0].set_title('Dilated Image')
    axs[0, 1].imshow(eroded, cmap='Greys'), axs[0, 1].set_title('Eroded Image')
    axs[1, 0].imshow(opening, cmap='Greys'), axs[1, 0].set_title('Opening')
    axs[1, 1].imshow(closing, cmap='Greys'), axs[1, 1].set_title('Closing')
    for ax in axs.flatten():
        ax.set_xticks([])
        ax.set_yticks([])
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    image = cv.imread('F:/004.JPG', cv.IMREAD_COLOR_RGB)
    morp_img(image)
