#include "InputHandler.h"
#include "raylib.h"
#include "constants.h"
#include <iostream>

void InputHandler::handleMouseInput(Grid &grid)
{
    Vector2 mousePos = GetMousePosition();

    int gridX = (int)((mousePos.x - consts::PADDING_LEFT) / consts::CELL_SIZE);
    int gridY = (int)((mousePos.y - consts::PADDING_H) / consts::CELL_SIZE);

    if (gridX > 0 && gridX < consts::GRID_W - 1 && gridY > 0 && gridY < consts::GRID_H - 1)
    {
        auto &cells = grid.getCells();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            if (cells[gridX][gridY].get_state() != 1)
            {
                cells[gridX][gridY].set_state(2);
                cells[gridX][gridY].set_concentration(100.0f);
                float *f_in = cells[gridX][gridY].get_f_in();
                for (int i = 0; i < 4; i++)
                    f_in[i] = consts::weighting_coefficient_D2Q4 * 100.0f;
            }
        }

        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        {
            cells[gridX][gridY].set_state(1);
            cells[gridX][gridY].set_concentration(0.0f);
            float *f_in = cells[gridX][gridY].get_f_in();
            for (int i = 0; i < 4; i++)
                f_in[i] = 0.0f;
        }

        else if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
        {
            cells[gridX][gridY].set_state(0);
            cells[gridX][gridY].set_concentration(0.0f);
            float *f_in = cells[gridX][gridY].get_f_in();
            for (int i = 0; i < 4; i++)
                f_in[i] = 0.0f;
        }
    }
}