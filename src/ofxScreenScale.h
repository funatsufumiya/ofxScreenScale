#pragma once

#include "ofMain.h"

class ofxScreenScale {
private:
    
public:
    static float getScreenScale();

    static void applyDrawScale();
    static void applyImGuiScale();

    static float getScaledWidth();
    static float getScaledHeight();
};
