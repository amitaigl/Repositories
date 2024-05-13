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

CComPtr<IMFDevice> g_cpLive;      //IMFDevice pointer

int EnumAndSelectVideoDevice(int nSelDevice)
{
	HRESULT hr = S_OK;
	CComBSTR cbsDevName;
	BOOL bBusy = false;
	/*if (nSelDevice > 0)
	{
		hr = g_cpLive->DeviceGetByIndex(eMFDT_Video, nSelDevice - 1, &cbsDevName, &bBusy);
		if (cbsDevName)
		{
			//Set video device
			hr = g_cpLive->DeviceSet(eMFDT_Video, nSelDevice - 1, CComBSTR(L""));
			return nSelDevice; //Device number is valid
		}
	}*/

	//Video device number wasn't specified as argument or number was incorrect
	//Enumerate devices
	int nCount = 0;
	hr = g_cpLive->DeviceGetCount(eMFDT_Video, &nCount);
	if (nCount == 0)
	{
		_tprintf(_T("No available live video devices found\n"));
		return 0;
	}

	_tprintf(_T("Supported video devices:\n\n"));
	for (int i = 0; i < nCount; i++)
	{
		g_cpLive->DeviceGetByIndex(eMFDT_Video, i, &cbsDevName, &bBusy);
		_tprintf(_T("%i: %s\n"), i + 1, cbsDevName);
	}
	_tprintf(_T("\n"));
	_tprintf(_T("Choose video device index:\n"));

	int nLiveDevice = 0;
	cin >> nLiveDevice;
	//Probe selected live device
	hr = g_cpLive->DeviceSet(eMFDT_Video, nLiveDevice - 1, CComBSTR(L""));
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't use this input device for capturing \n"));
		return 0;
	}
	return nLiveDevice;
}

HRESULT PlayLiveSource(int nSelVidDevice, int nSelVidDeviceLine, int nSelFormat)
{
	// Create MFLive instance
	HRESULT hr = g_cpLive.CoCreateInstance(__uuidof(MFLive));
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't create MFLive instance \n"));
		return E_FAIL;
	}

	//Initialize preview
	CComPtr<IMPreview> cpPreview;   //IMPreview pointer
	hr = cpPreview.CoCreateInstance(__uuidof(MFPreview));
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't create MFPreview instance \n"));
		return E_FAIL;
	}
	//Enable video and audio preview
	hr = cpPreview->PreviewEnable(CComBSTR(L""), true, true);

	//Enumerate and choose video device if needed
	int nVidDevice = EnumAndSelectVideoDevice(nSelVidDevice);
	if (nVidDevice == 0)
		return E_FAIL;  //No valid video device was selected

	/*Format func??*/

	_tprintf(_T("Capturing...  Press ESC to stop capturing from the device\n"));
	CComPtr<IMFFrame> cpFrame;
	CComQIPtr<IMFReceiver> cpReceiverPreview(cpPreview);
	CComQIPtr<IMFSource> cpSource(g_cpLive);
	M_AV_PROPS avProps = {};
	while (GetAsyncKeyState(VK_ESCAPE) == 0)
	{
		cpFrame = NULL;
		//Get frames one by one 
		hr = cpSource->SourceFrameConvertedGet(&avProps, -1, &cpFrame, CComBSTR(L""));
		if (cpFrame)
		{
			//Send frame to preview
			if (cpReceiverPreview)
				hr = cpReceiverPreview->ReceiverFramePut(cpFrame, -1, CComBSTR(L""));
			if (FAILED(hr))
				break;
		}
	}

	cpFrame = NULL;
	g_cpLive->DeviceClose();
	g_cpLive = NULL;

	return S_OK; // checking git.
}

int main()
{
	//Initialize COM
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't initialize COM \n"));
		return 0;
	}





	PlayLiveSource(0, 0, 0); //*** I need clean the arguments here!!

	::CoUninitialize();
	return 0;
}