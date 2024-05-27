#pragma once
#include "includes.hpp"
#include "devices.hpp"
#include "sources.hpp"
//#include "C:\lib\install\opencv\include\opencv2\core.hpp"
//#include "C:\lib\install\opencv\include\opencv2\highgui.hpp"
//#include "C:\lib\install\opencv\include\opencv2\imgcodecs.hpp"

namespace cv { class Mat; }
using namespace cv;

namespace BrandBrigade
{

class Frame
{
public:
	Frame();
	~Frame();

	HRESULT PutFrame();
	//CComPtr<IMFFrame>& GetMedialooksFrame();
	Mat& GetOpencvFrame();
	//Source& GetSource();

private:
	void Convert();

	Device m_device;
	Source m_source;
	//CComPtr<IMPreview> cpPreview; // change name to "m_shower"
	CComPtr<IMFFrame> cpFrame;
	Mat& m_opencvFrame;
};

} // BrandBrigade