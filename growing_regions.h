//
// Created by Dan Orel on 2019-11-02.
//
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#ifndef GROWINGREGIONS_GROWING_REGIONS_H
#define GROWINGREGIONS_GROWING_REGIONS_H
cv::Mat ApplyGrowingRegions(
        const cv::Mat &Image,
        const cv::Point point,
        const uchar threshold);
#endif //GROWINGREGIONS_GROWING_REGIONS_H
