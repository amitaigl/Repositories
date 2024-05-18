#pragma once
#include "includes.hpp"

namespace BrandBrigade
{

class Source
{
public:
	Source(CComPtr<IMFDevice> g_cpLive);

	CComQIPtr<IMFSource>& GetSource();
private:
	CComQIPtr<IMFSource> cpSource;

};

} // BrandBrigade