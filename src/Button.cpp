#include "Button.h"

Button::Button(float x, float y, float width, float height, const char* buttonText)
    : bounds{x, y, width, height}, 
      text(buttonText),
      normalColor(LIGHTGRAY),
      hoverColor(GRAY),
      pressedColor(DARKGRAY) {}

bool Button::isPressed() {
    Vector2 mousePos = GetMousePosition();
    
    if (CheckCollisionPointRec(mousePos, bounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            DrawRectangleRec(bounds, pressedColor);
            DrawRectangleLinesEx(bounds, 2, BLACK);
            DrawText(text, bounds.x + 10, bounds.y + 15, 20, WHITE);
            return false;
        } else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            DrawRectangleRec(bounds, hoverColor);
            DrawRectangleLinesEx(bounds, 2, BLACK);
            DrawText(text, bounds.x + 10, bounds.y + 15, 20, WHITE);
            return true; 
        } else {
            DrawRectangleRec(bounds, hoverColor);
            DrawRectangleLinesEx(bounds, 2, BLACK);
            DrawText(text, bounds.x + 10, bounds.y + 15, 20, WHITE);
        }
    } else {
        DrawRectangleRec(bounds, normalColor);
        DrawRectangleLinesEx(bounds, 2, BLACK);
        DrawText(text, bounds.x + 10, bounds.y + 15, 20, BLACK);
    }
    
    return false;
}

void Button::draw() {
    isPressed();
}