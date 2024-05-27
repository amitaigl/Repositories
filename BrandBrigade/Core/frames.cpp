#include "frames.hpp"
#include "opencv2/opencv.hpp"

namespace BrandBrigade
{

Frame::Frame() : m_device(), m_source(m_device.GetPtr()), cpFrame(NULL), m_opencvFrame(*new Mat())
{
	// meantime:
	//namedWindow("Video Window", WINDOW_AUTOSIZE);

}

Frame::~Frame()
{
	destroyAllWindows();
	delete & m_opencvFrame;
}

HRESULT Frame::PutFrame()
{
	M_AV_PROPS avProps = {};
	cpFrame = NULL;

	HRESULT hr = m_source.GetSource()->SourceFrameConvertedGet(&avProps, -1, &cpFrame, CComBSTR(L""));
	if(!cpFrame)
	{
		return E_FAIL;
	}

	Convert();
}

Mat& Frame::GetOpencvFrame()
{
	return m_opencvFrame;
}

//Source& Frame::GetSource()
//{
//	return m_source;
//}

void Frame::Convert()
{
	M_AV_PROPS* p_Props = NULL;
	long* _plAudioSamples = NULL;
	LONG* _pcbSize = NULL;
	LONGLONG* _ppbVideo = NULL;
	cpFrame->MFAVPropsGet(p_Props, _plAudioSamples);
	int width = p_Props->vidProps.nWidth;
	int hight = p_Props->vidProps.nHeight;
	int pixelFormat = p_Props->vidProps.eVideoFormat;

	cpFrame->MFVideoGetBytes(_pcbSize, _ppbVideo);

	//for trying:
	m_opencvFrame = Mat(hight, width, CV_8UC4, _pcbSize);
	//trying:
	//imshow("Video Window", m_opencvFrame);


	// RELEASE THE FRAME!!!!!!!!!!!!!

	/*CComPtr<IMFFrameSource> frameSourcePtr;
	framePtr->QueryInterface(IID_IMFFrameSource, (LPVOID*)&frameSourcePtr);*/

	// בדוק אם ההמרה צלחה
	//if (frameSourcePtr.IsNULL())
	//{
	//	// טיפול במקרה שגיאה
	//	return;
	//}

	// Extract format from MFFrameInfo (implementation might differ)
	//int format = info.dwFourCC; // Assuming format is stored in dwFourCC member
}

} // BrandBrigade