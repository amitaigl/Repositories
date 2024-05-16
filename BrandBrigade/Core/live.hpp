#include "includes.hpp"
#include "initializing.hpp"
#include "showing.hpp"
#include "devices.hpp"
#include "sources.hpp"

namespace BrandBrigade
{

class Live
{
public:
	__declspec(dllexport) Live();
	//Live(const Live& other) = delete;
	__declspec(dllexport) ~Live();

	__declspec(dllexport) void Run();//?????????????????????
private:
	Init m_starter;
	Device m_device;
	Source m_source;
	Show m_window;



	//// ----- Edit these members!!!!!!!!!!!!!!!!!!!!!!!!!
	//CComPtr<IMFFrame> cpFrame;
	//CComQIPtr<IMFReceiver> cpReceiverPreview;
	//CComQIPtr<IMFSource> cpSource;
	//M_AV_PROPS avProps; // ???????????????????????

	//Temp:
};
} // BrandBrigade