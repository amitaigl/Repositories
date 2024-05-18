#include "sources.hpp"

namespace BrandBrigade
{
Source::Source(CComPtr<IMFDevice> g_cpLive) : cpSource(g_cpLive)
{
}

CComQIPtr<IMFSource>& Source::GetSource()
{
	return cpSource;
}


} // BrandBrigade