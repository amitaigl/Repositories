// trying.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
#include "opencv2/opencv.hpp"*/


#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/* Not recommended main:
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << " Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file

    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", image); // Show our image inside it.

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}*/

int main()
{
    // Open video capture object
    VideoCapture cap("C:/Users/amita/Downloads/20240502_090008.mp4");
    if(!cap.isOpened())
    {
        std::cerr << "Error opening video capture object\n";
        return 1;
    }

    namedWindow("Video Window", WINDOW_AUTOSIZE);

    while(true)
    {
        Mat frame;
        if(!cap.read(frame))
        {
            std::cerr << "Error capturing frame\n";
            break;
        }

        imshow("Video Window", frame);

        /*// Exit loop on 'q' key press
        if(waitKey(1) == 'q')
        {
            break;
        }*/
    }

    // Release resources
    cap.release();
    destroyAllWindows();

    return 0;
}

