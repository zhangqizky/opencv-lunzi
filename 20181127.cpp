// **********************************
// author: tangxi.zq
// mail:   zhangqiwork123@gmail.com
// time:   20181127
// **********************************

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



void my_resize(Mat src, Mat dst, Size s, string inter_)
{

}

void sharpen(const Mat& myImage, const Mat& kernel, Mat& result)
{
	CV_Assert(myImage.depth() == CV_8U);

	result.create(myImage.size(), myImage.type());
	const int nChannels = myImage.channels();

	for (int j = 1; j < myImage.rows-1; ++j)
	{
		const uchar* previous = myImage.ptr<uchar>(j-1);
		const uchar* cur = myImage.ptr<uchar>(j);
		const uchar* post = myImage.ptr<uchar>(j+1);

		uchar* output = result.ptr<uchar>(j);

		for (int i = 1; i < nChannels*(myImage.cols - 1); ++i)
		{
			*output++ = saturate_cast<uchar>(5 * cur[i] - cur[i - nChannels] - cur[i + nChannels] - previous[i] - post[i]);
		}
	}
	result.row(0).setTo(Scalar(0));
	result.row(result.rows - 1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols - 1).setTo(Scalar(0));
}