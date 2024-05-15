#include "includes.hpp"

namespace BrandBrigade
{

class Device
{
public:
	Device();
	//~Device();

	CComPtr<IMFDevice>& GetPtr();

	void CreateInstance();
	void Run();
	void DisplayDevices();
	void EnumerateDevices(int& nCount);
	void SelectDevice();

private:
	CComPtr<IMFDevice> g_cpLive;
};
} // BrandBrigade