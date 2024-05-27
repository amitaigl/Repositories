#include "live.hpp"
#include "opencv2/opencv.hpp"

namespace BrandBrigade
{

Live::Live() : m_starter(), m_frame()
{
	Run();
}

Live::~Live()
{
	::CoUninitialize();
	destroyAllWindows();
}

void Live::Run()
{
	//_tprintf(_T("Capturing...  Press ESC to stop capturing from the device\n"));
	//cout << "Capturing...  Press ESC to stop capturing from the device" << endl;
	//CComPtr<IMFFrame> cpFrame = NULL;
	// temp:
	//Mat frame = Mat::zeros(Size(300, 300), CV_8UC3);
	Mat frame;
	//VideoCapture cap;

	namedWindow("Video Window", WINDOW_AUTOSIZE);


	while(GetAsyncKeyState(VK_ESCAPE) == 0)
	{
		//Get frames one by one
		HRESULT hr = m_frame.PutFrame();
		if (hr != S_OK)
		{
			break;
		}
		//frame = m_frame.GetOpencvFrame();
		//if (cpFrame)
		//{
		//	//Send frame to preview
		//	if (cpReceiverPreview)
		//		hr = cpReceiverPreview->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));
		//	if (FAILED(hr))
		//		break;
		//}
		//imshow("Video Window", frame);
		imshow("Video Window", m_frame.GetOpencvFrame());

	}
}

} // BrandBrigade