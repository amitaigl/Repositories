#pragma once

#include "includes.hpp"
#include "initializing.hpp"
#include "frames.hpp"

namespace BrandBrigade
{

class Live
{
public:
	__declspec(dllexport) Live();
	__declspec(dllexport) ~Live();

	__declspec(dllexport) void Run();//?????????????????????
private:
	Init m_starter;
	Frame m_frame;
	//Show m_window;



	//// ----- Edit these members!!!!!!!!!!!!!!!!!!!!!!!!!
	//CComPtr<IMFFrame> cpFrame;
	//CComQIPtr<IMFReceiver> cpReceiverPreview;
	//CComQIPtr<IMFSource> cpSource;
	//M_AV_PROPS avProps; // ???????????????????????

	//Temp:
};
} // BrandBrigade