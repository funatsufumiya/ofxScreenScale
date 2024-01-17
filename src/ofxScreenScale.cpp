#include "ofxScreenScale.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

float ofxScreenScale::getScreenScale()
{
#if defined(_WIN32) || defined(_WIN64)
	HDC screen = GetDC(NULL);
	int dpi = GetDeviceCaps(screen, LOGPIXELSX);
	ReleaseDC(NULL, screen);
	return dpi / 96.0f;
#else
	return 1.0f;
#endif
}
