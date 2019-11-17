//
// Created by Dan Orel on 2019-11-02.
//
#include "growing_regions.h"


cv::Mat ApplyGrowingRegions(
        const cv::Mat &Image,
        const cv::Point point,
        const uchar threshold){
    cv::Mat GrowingRegionsImage = Image.clone();
    // Initialize the dynamic mark array
    bool **marked = new bool*[GrowingRegionsImage.rows];
    for(int row = 0; row < GrowingRegionsImage.rows; row++){
        marked[row] = new bool[GrowingRegionsImage.cols];
    }
    // Initialize the array with zero-values
    for(int row = 0; row < GrowingRegionsImage.rows; row++){
        for(int col = 0; col < GrowingRegionsImage.cols; col++){
            marked[row][col] = false;
        }
    }
    // Get the brightness value of the point
    uchar brightness = GrowingRegionsImage.at<uchar>(point.y, point.x);
    // Iterate through image, mark the valuable points
    for(int row = 0; row < GrowingRegionsImage.rows; row++){
        for(int col = 0; col < GrowingRegionsImage.cols; col++){
            if(abs(GrowingRegionsImage.at<uchar>(row, col) - brightness) < threshold){
                marked[row][col] = true;
            }
        }
    }
    // Make the marked regions to the 255 value, either to 0
    for(int row = 0; row < GrowingRegionsImage.rows; row++){
        for(int col = 0; col < GrowingRegionsImage.cols; col++){
            if(marked[row][col]){
                GrowingRegionsImage.at<uchar>(row, col) = 255;
            } else {
                GrowingRegionsImage.at<uchar>(row, col) = 0;
            }
        }
    }

    // Free the memory per mark array of booleans
    for(int row = 0; row < GrowingRegionsImage.rows; row++){
        delete marked[row];
    }
    delete[] marked;
    return GrowingRegionsImage;
}