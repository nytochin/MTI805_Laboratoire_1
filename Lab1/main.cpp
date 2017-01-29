#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

using namespace std;

[STAThreadAttribute]
int main(int argc, char** argv)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Lab1::MyForm);
	//VideoCapture videoCapture(0);
	//bool quit = false;

	//if (!videoCapture.isOpened())  // if not success, exit program
	//{
	//	cout << "Cannot open the video camera." << endl;
	//	return -1;
	//}

	//namedWindow("camera", WINDOW_AUTOSIZE);

	//while (!quit) {

	//	Mat frame;

	//	if (!videoCapture.read(frame)) {
	//		cout << "Cannot read a frame from the video camera." << endl;
	//		break;
	//	}

	//	imshow("camera", frame);

	//	// if key 'q' is pressed
	//	if (waitKey(30) == 27) {
	//		quit = true;
	//	}
	//}

	//waitKey(0); // Wait for a keystroke in the window
	return 0;
}