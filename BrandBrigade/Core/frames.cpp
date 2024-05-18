#include "frames.hpp"
#include "opencv2/opencv.hpp"

namespace BrandBrigade
{

Frame::Frame() : m_device(), m_source(m_device.GetPtr()), cpFrame(NULL), m_frame(*new Mat())
{
	// meantime:
	namedWindow("Video Window", WINDOW_AUTOSIZE);

}

Frame::~Frame()
{
	destroyAllWindows();
	delete &m_frame;
}

void Frame::PutFrame()
{

	Convert();
}

Mat& Frame::GetFrame()
{
	Mat blabla;
	// TODO: insert return statement here
	return blabla;
}

Source& Frame::GetSource()
{
	return m_source;
}

void Frame::Convert()
{
}

} // BrandBrigade