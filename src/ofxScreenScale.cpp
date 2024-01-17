#include "ofxScreenScale.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#if __has_include("ofxImGui.h")
#include "ofxImGui.h"
#endif

float ofxScreenScale::getScreenScale()
{
#if defined(_WIN32) || defined(_WIN64)
	SetProcessDPIAware();
	HDC screen = GetDC(NULL);
	int dpi = GetDeviceCaps(screen, LOGPIXELSX);
	ReleaseDC(NULL, screen);
	return dpi / 96.0f;
#else
	return 1.0f;
#endif
}

void ofxScreenScale::applyDrawScale()
{
	float scale = getScreenScale();
	ofScale(scale, scale);
}

void ofxScreenScale::applyImGuiScale()
{
#ifdef IMGUI_VERSION
	float scale = getScreenScale();

	// apply scaling to imgui
	auto& style = ImGui::GetStyle();
	style.ScaleAllSizes(scale);

	// apply font scaling to imgui
	auto&& io = ImGui::GetIO();
	io.FontGlobalScale = scale;
#endif
}
