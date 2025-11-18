#include <iostream>
#include <iomanip>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "quality/IoU.cpp"
using std::cout;
using namespace cv;

void process(std::string name) {
   cv::Mat src1 = cv::imread("/home/stanislav/mipt2025f-4-improc/data/walnut01/" + name + ".tif", cv::IMREAD_UNCHANGED );
   cv::Mat res;
   src1.convertTo(res, CV_8UC1, 255 / 0.06);
   cv::imwrite("/home/stanislav/mipt2025f-4-improc/data/processed/" + name + ".png", res);
}

int main() {
   std::ifstream input("../image_numes.txt");
   std::string name;
   while (input >> name) {
     std::cout << name << '\n';
     process(name);
   }
   return 0;
}