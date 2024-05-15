
#include "live.hpp"

Live::Live()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		_tprintf(_T("ERROR: Can't initialize COM \n"));
		return 0;
	}
}

Live::~Live()
{
	::CoUninitialize();
}
