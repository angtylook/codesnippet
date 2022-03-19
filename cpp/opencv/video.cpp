#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

const std::string kWinName = "example3";

int main(int argc, char** argv) {
    cv::namedWindow(kWinName, cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        cv::imshow(kWinName, frame);
        if (cv::waitKey(33) >= 0) {
            break;
        }
    }
    return 0;
}