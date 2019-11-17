#include <iostream>
#include "growing_regions.h"

int main() {
    std::string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/GrowingRegions/";
    std::string image = "objects2.jpg";
    std::string RegularImageLabel = "Growing Regions Image";
    std::string GrowingRegionsLabel = "Growing Regions Image";

    cv::Mat Image = cv::imread(
            (pathToImage + image),
            cv::IMREAD_GRAYSCALE);
    cv::Mat GrowingRegionsImage;
    cv::Point Point = cv::Point(100, 100);
    GrowingRegionsImage = ApplyGrowingRegions(
            Image,
            Point,
            1);
    imshow(RegularImageLabel, Image);
    imshow(GrowingRegionsLabel, GrowingRegionsImage);
    cv::waitKey();
    return 0;
}

