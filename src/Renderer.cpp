#include "Renderer.h"
#include "raylib.h"
#include "constants.h"
#include <algorithm>
#include <cmath>

void Renderer::drawGrid()
{
    for (int i = 0; i <= consts::GRID_W; i++)
    {
        DrawLine(consts::PADDING_LEFT + i * consts::CELL_SIZE, consts::PADDING_H,
                 consts::PADDING_LEFT + i * consts::CELL_SIZE, consts::PADDING_H + consts::GRID_H * consts::CELL_SIZE,
                 LIGHTGRAY);
    }
    for (int j = 0; j <= consts::GRID_H; j++)
    {
        DrawLine(consts::PADDING_LEFT, consts::PADDING_H + j * consts::CELL_SIZE,
                 consts::PADDING_LEFT + consts::GRID_W * consts::CELL_SIZE, consts::PADDING_H + j * consts::CELL_SIZE,
                 LIGHTGRAY);
    }
}

void Renderer::drawGridWithColors(const Grid &grid)
{
    const auto &cells = grid.getCells();

    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            int gridX = consts::PADDING_LEFT + i * consts::CELL_SIZE;
            int gridY = consts::PADDING_H + j * consts::CELL_SIZE;

            Color cellColor = RAYWHITE;
            int state = cells[i][j].get_state();

            if (state == 1)
            {
                cellColor = BLACK;
            }
            else if (state == 2)
            {

                cellColor = RED;
            }
            else
            {
                float conc = cells[i][j].get_concentration();
                if (conc > 0.001f)
                {
                    float normalized = std::min(conc / 1.0f, 1.0f);

                    unsigned char intensity = (unsigned char)(255 * (1.0f - normalized));
                    cellColor = (Color){intensity, intensity, 255, 255};
                }
                else
                {
                    cellColor = RAYWHITE;
                }
            }

            DrawRectangle(gridX, gridY, consts::CELL_SIZE, consts::CELL_SIZE, cellColor);
        }
    }
}