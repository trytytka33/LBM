#include "Renderer.h"
#include "raylib.h"
#include "constants.h"

void Renderer::drawGrid() {
    for (int i = consts::PADDING_LEFT; 
         i <= consts::GRID_W * consts::CELL_SIZE + consts::PADDING_LEFT; 
         i += consts::CELL_SIZE) {
        DrawLine(i, consts::PADDING_H, 
                 i, consts::GRID_H * consts::CELL_SIZE + consts::PADDING_H, 
                 BLACK);
    }
    
    for (int j = consts::PADDING_H; 
         j <= consts::GRID_H * consts::CELL_SIZE + consts::PADDING_H; 
         j += consts::CELL_SIZE) {
        DrawLine(consts::PADDING_LEFT, j, 
                 consts::GRID_W * consts::CELL_SIZE + consts::PADDING_LEFT, j, 
                 BLACK);
    }
}

void Renderer::drawGridWithColors(const Grid& grid) {
    for (int i = 0; i < consts::GRID_W; i++) {
        for (int j = 0; j < consts::GRID_H; j++) {
            int gridX = consts::PADDING_LEFT + i * consts::CELL_SIZE;
            int gridY = consts::PADDING_H + j * consts::CELL_SIZE;
            
            if (grid[i][j] == consts::CELL_OBSTACLE) {
                DrawRectangle(gridX, gridY, consts::CELL_SIZE, consts::CELL_SIZE, BLACK);
            } else if (grid[i][j] == consts::CELL_FLUID) {
                float C = grid[i][j].get_concentration();
                unsigned char intensity = (unsigned char)(C * 255);
                Color fluidColor = {0, 0, intensity, 255}; 
                DrawRectangle(gridX, gridY, consts::CELL_SIZE, 
                             consts::CELL_SIZE, fluidColor);
            }
        }
    }
}