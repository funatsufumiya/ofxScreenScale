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