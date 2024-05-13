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

int main()
{
	//Initialize COM
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't initialize COM \n"));
		return 0;
	}
}