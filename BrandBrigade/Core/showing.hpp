#include "includes.hpp"
#include "frames.hpp"

namespace BrandBrigade
{

class Show
{
public:
	Show();


private:
	CComPtr<IMPreview> cpPreview; // change name to "m_shower"
	//CComQIPtr<IMFReceiver> cpReceiverPreview(cpPreview);
	Frame m_frame;

};

} // BrandBrigade