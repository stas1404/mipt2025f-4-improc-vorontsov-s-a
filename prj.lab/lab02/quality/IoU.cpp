#include "opencv2/opencv.hpp"

double IoU(const cv::Mat& first, const cv::Mat& second) {
    return double(
              cv::countNonZero(first - (first - second))
           )
           /
           double(cv::countNonZero(first + second));
}

size_t TruePositive(const cv::Mat& etalon, const cv::Mat& result) {
    return cv::countNonZero(result - (result - etalon));
}

size_t TrueNegative(const cv::Mat& etalon, const cv::Mat& result) {
    return cv::countNonZero(- result);
}

size_t FalsePositive(const cv::Mat& etalon, const cv::Mat& result) {
    return cv::countNonZero(result - etalon);
}

size_t FalseNegative(const cv::Mat& etalon, const cv::Mat& result) {
    return cv::countNonZero(etalon - result);
}