#!/usr/local/bin/env python3
# encoding=utf-8

import cv2
import numpy as np
import cv_util

def threshold(image :cv2.UMat, threshold_v : int, max_v: int):
    img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # v > threshold_v ? max_v : 0
    ret, thresh1 = cv2.threshold(img, threshold_v, max_v, cv2.THRESH_BINARY)
    # v > threshold_v ? 0 : max_v
    ret, thresh2 = cv2.threshold(img, threshold_v, max_v, cv2.THRESH_BINARY_INV)
    # v > threshold_v ? threshold_v : v
    ret, thresh3 = cv2.threshold(img, threshold_v, max_v, cv2.THRESH_TRUNC)
    # v > threshold_v ? v : 0
    ret, thresh4 = cv2.threshold(img, threshold_v, max_v, cv2.THRESH_TOZERO)
    # v > threshold_v ? 0 : v
    ret, thresh5 = cv2.threshold(img, threshold_v, max_v, cv2.THRESH_TOZERO_INV)

    cv2.imshow('Binary Threshold', thresh1) 
    cv2.imshow('Binary Threshold Inverted', thresh2) 
    cv2.imshow('Truncated Threshold', thresh3) 
    cv2.imshow('Set to 0', thresh4) 
    cv2.imshow('Set to 0 Inverted', thresh5)

    if cv2.waitKey(0) & 0xff == 27:
        cv2.destroyAllWindows()

def threshold_adapt(image : cv2.UMat, max_v: int):
    img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    threshod1 = cv2.adaptiveThreshold(img, max_v, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 199, 5)
    threshod2 = cv2.adaptiveThreshold(img, max_v, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 199, 5)
    cv2.imshow("Adaptive Mean", threshod1)
    cv2.imshow("Adaptive Gaussian", threshod2)

    if cv2.waitKey(0) & 0xff == 27:
        cv2.destroyAllWindows()

def threshold_otsu(image : cv2.Mat, max_v: int):
    img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    ret, threshold1 = cv2.threshold(img, 0, max_v, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    cv2.imshow("Otsu Threshold", threshold1)
    if cv2.waitKey(0) & 0xff == 27:
        cv2.destroyAllWindows()


if __name__ == '__main__':
    image = cv_util.read_resize_aspect("F:/004.JPG")
    cv2.imshow("src", image)
    #threshold(image, 120, 255)
    #threshold_adapt(image, 255)
    threshold_otsu(image, 255)



