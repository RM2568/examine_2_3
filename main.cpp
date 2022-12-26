#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //读取图片并显示
    Mat img = imread("D:\\OpenCv4.1.1\\packages\\img\\board.jpg");    // 这边修改成自己的图片路径，注意双斜杠
    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }
    imshow("image", img);

    //图像预处理--颜色转换
    Mat grayimg;
    cvtColor(img,grayimg,COLOR_BGR2GRAY);
    namedWindow("灰度图像");
    imshow("灰度图像",grayimg);

    //图像预处理--边缘检测
    Mat edgeimg;
    Canny(grayimg, edgeimg, 30, 80);
    namedWindow("边缘检测图像");
    imshow("边缘检测图像",edgeimg);

    //图片与处理--高斯滤波图(3x3)
    Mat gauss;
    GaussianBlur(img,gauss,Size(5,5),10,20);
    namedWindow("高斯滤波图像");
    imshow("高斯滤波图像",gauss);

    //霍夫变换识别直线
    Mat lineimg;
    Canny(grayimg,lineimg,50,200,3);
    namedWindow("霍夫变换识别直线图像");
    imshow("霍夫变换识别直线图像",lineimg);

    waitKey(0);

    return 0;
}

