#!/usr/local/bin/env python3
# encoding=utf-8

import cv2

def read_resize_aspect(filename :str, width: int = 640):
    image = cv2.imread(filename)
    h, w = image.shape[:2]
    ratio = width / w
    dim =(width, int(h*ratio))
    resize_aspect = cv2.resize(image, dim)
    return resize_aspect

