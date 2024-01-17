# ofxScreenScale

- Get screen scale (ex: if using 4K screen, but setting 200% display)
- openFrameworks addon (tested on oF v0.12.0)

## Usage

```cpp
#include "ofxScreenScale.h"

void ofApp::setup(){
    ofLogToConsole();

    float scale = ofxScreenScale::getScreenScale();
    ofLogNotice("ofApp") << "screen scale: " << scale;
}
```

## Notes

- first, set proper window size on `main.cpp`:

```cpp
#include "ofMain.h"
#include "ofApp.h"
#include "ofxScreenScale.h"

int main( ){

	float scale = ofxScreenScale::getScreenScale();
	ofLogNotice("main") << "Screen scale: " << scale;

	ofGLWindowSettings settings;
	settings.setSize(1024 * scale, 768 * scale); // <--
	settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
```

- if you want to apply scale, just `ofScale` on draw:

```cpp
void ofApp::draw(){
    float scale = ofxScreenScale::getScreenScale();
    ofScale(scale, scale);

    // draw something...
}
```

- if you using `ofxImGui`, you need additional settings on `setup`:

```cpp
void ofApp::setup(){
    float scale = ofxScreenScale::getScreenScale();

    // apply scaling to imgui
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(scale);

    // apply font scaling to imgui
    auto&& io = ImGui::GetIO();
    io.FontGlobalScale = scale;
}
```