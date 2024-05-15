#include "showing.hpp"

namespace BrandBrigade
{

Show::Show()
{
	HRESULT hr = cpPreview.CoCreateInstance(__uuidof(MFPreview));
	if(FAILED(hr))
	{
		/*_tprintf(_T("ERROR: Can't create MFPreview instance \n"));
		return E_FAIL;*/
		throw("ERROR: Can't create MFPreview instance");
	}
	//Enable video and audio preview
	hr = cpPreview->PreviewEnable(CComBSTR(L""), true, true);
}

} // BrandBrigade