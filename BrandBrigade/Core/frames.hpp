#include "includes.hpp"

namespace BrandBrigade
{

class Frame
{
public:
	Frame();

private:
	CComPtr<IMFFrame> cpFrame;
};

} // BrandBrigade