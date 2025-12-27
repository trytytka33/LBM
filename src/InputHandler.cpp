#include "InputHandler.h"
#include "raylib.h"
#include "constants.h"

void InputHandler::handleMouseInput(Grid& grid) {
    int x = GetMouseX();
    int y = GetMouseY();
    int pixelX = (x - consts::PADDING_LEFT) / consts::CELL_SIZE;
    int pixelY = (y - consts::PADDING_H) / consts::CELL_SIZE;
    
    if (pixelX >= 0 && pixelX < consts::GRID_W && 
        pixelY >= 0 && pixelY < consts::GRID_H) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            grid.setGrid(pixelX, pixelY, consts::CELL_FLUID);
        }
    }
}