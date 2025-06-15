#!/usr/local/bin/env python3
# encoding=utf-8

import cv2
import random
import pathlib

def read_resize_aspect(filename :str, mode :int = cv2.IMREAD_COLOR_RGB, width: int = 640):
    image = cv2.imread(filename, mode)
    h, w = image.shape[:2]
    ratio = width / w
    dim =(width, int(h*ratio))
    resize_aspect = cv2.resize(image, dim)
    return resize_aspect

def read_example_img(mode :int = cv2.IMREAD_COLOR_RGB):
    dir1 = pathlib.Path("E:/2025/p1")
    file_list = list(dir1.glob("*.png"))
    file_list.extend(list(dir1.glob("*.jpg")))
    return read_resize_aspect(random.choice(file_list), mode)

def read_example_img_gray():
    dir1 = pathlib.Path("E:/2025/p1")
    file_list = list(dir1.glob("*.png"))
    file_list.extend(list(dir1.glob("*.jpg")))
    return read_resize_aspect(random.choice(file_list), cv2.IMREAD_GRAYSCALE)