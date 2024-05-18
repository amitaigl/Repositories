#include "includes.hpp"

namespace BrandBrigade
{

class Device
{
public:
	Device();
	//~Device();

	CComPtr<IMFDevice>& GetPtr();


private:
	CComPtr<IMFDevice> g_cpLive;

	void Run();
	void CreateInstance();
	void DisplayDevices();
	void SelectDevice();
	void EnumerateDevices(int& nCount);
};
} // BrandBrigade