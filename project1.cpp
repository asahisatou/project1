#include <opencv2/opencv.hpp>

int main() {
 cv::Mat img;
 img = cv::imread("/usr/local/pictures/chibany043.jpg");
 cv::Mat gray;
 cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
 cv::imshow("title", gray);
 cv::waitKey(0);

 return 0;
}
