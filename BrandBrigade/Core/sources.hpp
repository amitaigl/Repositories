#include "includes.hpp"

namespace BrandBrigade
{

class Source
{
public:
	Source(CComPtr<IMFDevice> g_cpLive);
private:
	CComQIPtr<IMFSource> cpSource;

};

} // BrandBrigade