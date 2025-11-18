#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using std::cout;
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1;
Mat dst;
static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
   addWeighted( src1, alpha, src1, beta, 0.0, dst);
   imshow( "Linear Blend", dst );
}
int main( void )
{
   src1 = imread("/home/stanislav/mipt2025f-4-improc/data/walnut01/walnut01.2250.tif", cv::IMREAD_UNCHANGED );
   alpha_slider = 0;
   namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
   char TrackbarName[50];
   sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
   createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
   on_trackbar( alpha_slider, 0 );
   waitKey(0);
   return 0;
}