#pragma once
#include <atlbase.h>

#include "MFormats.h"


class Live
{
public:
	Live();
	~Live();

private:
	HRESULT hr;
	CComPtr<IMFFrame> cpFrame;
	CComQIPtr<IMFReceiver> cpReceiverPreview;
	CComQIPtr<IMFSource> cpSource;
	M_AV_PROPS avProps;

	//Temp:
	CComPtr<IMPreview> cpPreview;
};