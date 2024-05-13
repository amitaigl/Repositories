#pragma once

#include <stdio.h>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#include <atlbase.h>
#include <atlstr.h>
#include <SDKDDKVer.h>
//#include "stdafx.h"

#include <iostream>
#include "MFormats.h"
//#include "Include/ArgParse/get_arguments.h"
//#include "Include/ArgParse/platform_os.h"

#ifndef __IMFReader_FWD_DEFINED__
#define __IMFReader_FWD_DEFINED__
typedef interface IMFReader IMFReader;
#endif 	/* __IMFReader_FWD_DEFINED__ */

#ifndef __IMPreview_FWD_DEFINED__
#define __IMPreview_FWD_DEFINED__
typedef interface IMPreview IMPreview;
#endif 	/* __IMPreview_FWD_DEFINED__ */

using namespace std;

HRESULT GetVideo(CComBSTR cbsFileName)
{
	CComPtr<IMFReader> cpReader;    //IMFReader pointer
	CComPtr<IMPreview> cpPreview;   //IMPreview pointer

	M_AV_PROPS avProps = {};        //Video props structure
	CComBSTR _cbsProps{ _T("") };

	// Create MFReader instance
	HRESULT hr = cpReader.CoCreateInstance(__uuidof(MFReader));
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't create MFReader instance \n"));
		return E_FAIL;
	}
	
	//Open File
	hr = cpReader->ReaderOpen(cbsFileName, _cbsProps);
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't open this media file\n"));
		return E_FAIL;
	}

	//Initialize preview
	hr = cpPreview.CoCreateInstance(__uuidof(MFPreview));
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't create MFPreview instance \n"));
		return E_FAIL;
	}

	//Enable video and audio preview
	hr = cpPreview->PreviewEnable(CComBSTR(L""), true, true);

	CComPtr<IMFFrame> cpFrame;
	CComQIPtr<IMFReceiver> cpReceiverPreview(cpPreview);
	//CComQIPtr<IMFReceiver> cpReceiverRenderer(cpRenderer);
	M_TIME mTime = {};

	//Get frames one by one from the source file and send them to preview/renderer
	_tprintf(_T("Playing... Press ESC to stop playback\n"));
	bool bRewind{ false };
	while (GetAsyncKeyState(VK_ESCAPE) == 0)
	{
		cpFrame = NULL;
		//Get frame by number. -1 as frame number means next frame
		if (bRewind)
		{
			hr = cpReader->SourceFrameConvertedGetByNumber(&avProps, 0, -1, &cpFrame, CComBSTR(L""));
			bRewind = false;
		}
		else
		{
			hr = cpReader->SourceFrameConvertedGetByTime(&avProps, -1, -1, &cpFrame, CComBSTR(L""));
		}
		if (cpFrame)
		{
			//Check for the last frame to stop the playback
			hr = cpFrame->MFTimeGet(&mTime);
			/*if ((mTime.eFFlags & eMFF_Last) != 0)
			{
				if (_bLoop)
					bRewind = true;
				else
					break;
			}*/
			//Send frame to preview
			if (cpReceiverPreview)
				cpReceiverPreview->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));

			/*if (cpSink)
				cpSink->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));*/

			//Send frame to renderer
			/*if (nRenderer > 0 && cpReceiverRenderer)
				cpReceiverRenderer->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));*/
		}
	}

	/*if (cpRenderer)
		cpRenderer->DeviceClose();*/
	if (cpReader)
		cpReader->ReaderClose();
	/*if (cpSink)
		cpSink->SinkClose();*/

	cpFrame = NULL;
	/*cpRenderer = NULL;*/
	cpReader = NULL;

	return S_OK;
}

int main(int argc, char* argv[])
{
	
	
	//Initialize COM
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't initialize COM \n"));
		return 0;
	}

	/*for (int i = 0; i < argc; ++i) {
		std::cout << "Argument " << i + 1 << ": " << argv[i] << std::endl;
	}*/

	CComBSTR cbsFileName = CComBSTR(argv[1]);            //Path to media file
	/*printf("the length is: %d\n", cbsFileName.Length());
	printf("the argc is: %d\n", argc);*/

	GetVideo(cbsFileName);

	::CoUninitialize();
	return 0;
}