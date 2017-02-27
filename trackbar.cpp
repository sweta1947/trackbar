#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main()
{
	int f = 10;
	Mat var1 = imread("images.jpg", 1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	cvtColor(var1, var2, CV_RGB2GRAY);
	namedWindow("windows1",WINDOW_AUTOSIZE );
	createTrackbar("track", "windows1", &f, 255);
	while (1)
	{
		for (int i = 0; i < var1.rows; i++){
			for (int j = 0; j < var1.cols; j++)
			{
				if (var2.at<uchar>(i, j) < f)
					var3.at<uchar>(i, j) = 0;
				else
					var3.at<uchar>(i, j) = 255;
			}
		}
		namedWindow("windows2", WINDOW_AUTOSIZE);
			imshow("windows2", var3);
			waitKey(0);
	}
	return(0);
}
