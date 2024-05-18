#include "devices.hpp"

namespace BrandBrigade
{

Device::Device() : g_cpLive(NULL)
{
	CreateInstance();

	Run();
}

/*Device::~Device()
{
}*/

CComPtr<IMFDevice>& Device::GetPtr()
{
	return g_cpLive;
}

void Device::CreateInstance()
{
	HRESULT hr = S_OK;

	hr = g_cpLive.CoCreateInstance(__uuidof(MFLive));
	if(FAILED(hr))
	{
		throw("ERROR: Can't create MFLive instance\n");
	}
}

void Device::Run()
{
	DisplayDevices();
	SelectDevice();
}



void Device::DisplayDevices()
{
	CComBSTR cbsDevName;
	BOOL bBusy = false;
	int nCount = 0;

	EnumerateDevices(nCount);

	cout << "Supported video devices:\n" << endl;
	for(int i = 0; i < nCount; i++)
	{
		g_cpLive->DeviceGetByIndex(eMFDT_Video, i, &cbsDevName, &bBusy);
		cout << i + 1 << ": " << cbsDevName << endl;
	}
}

void Device::EnumerateDevices(int& nCount)
{
	HRESULT hr = S_OK;

	hr = g_cpLive->DeviceGetCount(eMFDT_Video, &nCount);
	if(nCount == 0)
	{
		throw("No available live video devices found\n");
	}
}

void Device::SelectDevice()
{
	cout << "\nChoose video device index:\n";

	int nLiveDevice = 0;
	cin >> nLiveDevice;

	HRESULT hr = S_OK;
	hr = g_cpLive->DeviceSet(eMFDT_Video, nLiveDevice - 1, CComBSTR(L""));
	if(FAILED(hr))
	{
		throw("ERROR: Can't use this input device for capturing\n");
	}
}

} // BrandBrigade