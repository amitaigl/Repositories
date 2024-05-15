#include "pch.h"
#include "live.hpp"

namespace BrandBrigade
{

Live::Live() : m_source(m_device.GetPtr())
{
	HRESULT hr = S_OK;

	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if(FAILED(hr))
	{
		/*_tprintf(_T("ERROR: Can't initialize COM \n"));
		return 0;*/
		cout << "ERROR: Can't initialize COM\n";
	}

	Run();
}

Live::~Live()
{
	::CoUninitialize();
}

void Live::Run()
{
	//_tprintf(_T("Capturing...  Press ESC to stop capturing from the device\n"));
	cout << "Capturing...  Press ESC to stop capturing from the device" << endl;

	//while(GetAsyncKeyState(VK_ESCAPE) == 0)
	//{
	//	cpFrame = NULL;
	//	//Get frames one by one 
	//	hr = cpSource->SourceFrameConvertedGet(&avProps, -1, &cpFrame, CComBSTR(L""));
	//	if (cpFrame)
	//	{
	//		//Send frame to preview
	//		if (cpReceiverPreview)
	//			hr = cpReceiverPreview->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));
	//		if (FAILED(hr))
	//			break;
	//	}
	//}
}

} // BrandBrigade