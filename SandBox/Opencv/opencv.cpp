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
    std::cout << "Hello World!\n";

    // Open video capture object
    VideoCapture cap("C:/Users/amita/Downloads/20240502_090008.mp4"); // Replace with your video path

    // Check if video capture was successful
    if (!cap.isOpened()) {
        std::cerr << "Error opening video capture object\n";
        return 1;
    }

    // Create a named window for display
    namedWindow("Video Window", WINDOW_AUTOSIZE);

    while (true) {
        // Capture frame-by-frame
        Mat frame;
        if (!cap.read(frame)) {
            std::cerr << "Error capturing frame\n";
            break;
        }

        // Display the resulting frame
        imshow("Video Window", frame);

        // Exit loop on 'q' key press
        if (waitKey(1) == 'q') {
            break;
        }
    }

    // Release resources
    cap.release();
    destroyAllWindows();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
