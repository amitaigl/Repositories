#include "pch.h"
#include "initializing.hpp"

namespace BrandBrigade
{

Init::Init()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		throw("ERROR: Can't initialize COM \n");
	}
}

Init::~Init()
{
	::CoUninitialize();
}

} // BrandBrigade

