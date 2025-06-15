#!/usr/local/bin/env python3
# encoding=utf-8

import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def resize_img(image : cv.Mat):
    half = cv.resize(image, (0,0), fx=0.1, fy=0.1)
    bigger = cv.resize(image, (1050, 1601))
    stretch_near = cv.resize(image, (780,540), interpolation=cv.INTER_LINEAR)
    Titles = ["Original", "Half", "Bigger", "Interpolation Nearest"]
    images = [image, half, bigger, stretch_near]
    count = 4
    for i in range(count):
        plt.subplot(2,2,i+1)
        plt.title(Titles[i])
        plt.imshow(images[i])
    plt.show()

def rotate_img(image : cv.Mat):
    # shape[0] = row, shape[1] = cols
    center = (image.shape[1]//2, image.shape[0]//2)
    angle = 30  # < 0 顺时针 > 0 逆时针
    scale = 1
    rotation_matrix = cv.getRotationMatrix2D(center, angle, scale)
    rotated_image = cv.warpAffine(image, rotation_matrix, (image.shape[1], image.shape[0]))
    fig, axs = plt.subplots(1,2, figsize=(7,4))
    axs[0].imshow(image)
    axs[0].set_title('Original Image')
    axs[1].imshow(rotated_image)
    axs[1].set_title('Image Rotation')
    for ax in axs:
        ax.set_xticks([])
        ax.set_yticks([])
    plt.tight_layout()
    plt.show()

def translate_img(image : cv.Mat):
    # shape[0] = row, shape[1] = cols
    width, height = image.shape[1], image.shape[0]
    tx, ty = 100, 70
    
    translation_matrix = np.array([[1,0, tx], [0,1, ty]], dtype=np.float32)
    translation_image = cv.warpAffine(image, translation_matrix, (width, height))
    fig, axs = plt.subplots(1,2, figsize=(7,4))
    axs[0].imshow(image)
    axs[0].set_title('Original Image')
    axs[1].imshow(translation_image)
    axs[1].set_title('Image Translation')
    for ax in axs:
        ax.set_xticks([])
        ax.set_yticks([])
    plt.tight_layout()
    plt.show()

def shear_img(image : cv.Mat):
    # shape[0] = row, shape[1] = cols
    width, height = image.shape[1], image.shape[0]
    shearx, sheary = -0.15, 0

    
    translation_matrix = np.array([[1,shearx, 0], [0,1, sheary]], dtype=np.float32)
    sheared_image = cv.warpAffine(image, translation_matrix, (width, height))
    fig, axs = plt.subplots(1,2, figsize=(7,4))
    axs[0].imshow(image)
    axs[0].set_title('Original Image')
    axs[1].imshow(sheared_image)
    axs[1].set_title('Image Sheared')
    for ax in axs:
        ax.set_xticks([])
        ax.set_yticks([])
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    image = cv.imread('F:/004.JPG', cv.IMREAD_COLOR_RGB)
    #resize_img(image)
    #rotate_img(image)
    #translate_img(image)
    shear_img(image)
