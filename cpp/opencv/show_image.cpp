#include <iostream>

#include "opencv2/opencv.hpp"

int main(int argc, char ** argv) {
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_UNCHANGED);
    if (img.empty())
        return -1;
    cv::namedWindow("example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("example1", img);
    cv::waitKey(0);
    cv::destroyWindow("example1");
    return 0;
}