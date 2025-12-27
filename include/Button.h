#pragma once
#include <vector>
#include "raylib.h"

class Button {
private:
    Rectangle bounds;
    const char* text;
    Color normalColor;
    Color hoverColor;
    Color pressedColor;
    
public:
    Button(float x, float y, float width, float height, const char* buttonText);
    
    bool isPressed();
    void draw();
};