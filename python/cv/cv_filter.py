#!/usr/local/bin/env python3
# encoding=utf-8

import cv2 as cv
import numpy as np

def filter_cap():
    cap = cv.VideoCapture(0)
    while(1):
        _, frame = cap.read()
        hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
        lower_blue = np.array([60,35,140])
        upper_blue = np.array([180,255,255])
        mask = cv.inRange(hsv, lower_blue, upper_blue)
        result = cv.bitwise_and(frame, frame, mask)

        cv.imshow("frame", frame)
        cv.imshow("mask", mask)
        cv.imshow("result", result)
        if cv.waitKey(0) & 0xFF == 27:
            break

    cv.destroyAllWindows()
    cap.release()

if __name__ == '__main__':
    filter_cap()
