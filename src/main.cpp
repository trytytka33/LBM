#include "raylib.h"
#include "constants.h"
#include "Grid.h"
#include "Button.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "Simulation.h"
#include <iostream>

int main()
{
    const char *title = "LBM Diffusion Simulation - D2Q4";
    InitWindow(consts::WINDOW_W, consts::WINDOW_H, title);
    SetTargetFPS(60);

    Grid grid;
    Simulation simulation;
    int stepCounter = 0;

    Button startButton(50, consts::PADDING_H,
                       consts::BUTTON_W, consts::BUTTON_H, "Start");
    Button clearButton(50, consts::PADDING_H + consts::BUTTON_H + 20,
                       consts::BUTTON_W, consts::BUTTON_H, "Clear");
    Button resetButton(50, consts::PADDING_H + 2 * (consts::BUTTON_H + 20),
                       consts::BUTTON_W, consts::BUTTON_H, "Reset");

    bool simulationRunning = false;

    while (!WindowShouldClose())
    {
        if (startButton.isPressed())
        {
            simulationRunning = !simulationRunning;
        }

        if (clearButton.isPressed())
        {
            simulationRunning = false;
            grid.reset();
            stepCounter = 0;
        }

        if (resetButton.isPressed())
        {
            simulationRunning = false;
            grid.init_grid();
            stepCounter = 0;
        }

        if (!simulationRunning)
        {
            InputHandler::handleMouseInput(grid);
        }

        if (simulationRunning)
        {
            auto &cells = grid.getCells();
            for (int i = 0; i < consts::GRID_W; i++)
            {
                for (int j = 0; j < consts::GRID_H; j++)
                {
                    if (cells[i][j].get_state() != 1)
                    {
                        simulation.collision(cells[i][j], 1.0f, 1.0f);
                    }
                }
            }

            simulation.streaming(cells);

            for (int i = 0; i < consts::GRID_W; i++)
            {
                for (int j = 0; j < consts::GRID_H; j++)
                {
                    if (cells[i][j].get_state() == 2)
                    {
                        float *f_in = cells[i][j].get_f_in();
                        for (int k = 0; k < consts::num_of_directions; k++)
                        {
                            f_in[k] = consts::weighting_coefficient_D2Q4 * 100.0f;
                        }
                        cells[i][j].set_concentration(100.0f);
                    }
                }
            }
            stepCounter++;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Renderer::drawGridWithColors(grid);
        Renderer::drawGrid();
        startButton.draw();
        clearButton.draw();
        resetButton.draw();
        DrawText(TextFormat("Steps: %d", stepCounter), 50,
                 consts::PADDING_H + 3 * (consts::BUTTON_H + 20), 20, BLACK);
        DrawText(simulationRunning ? "RUNNING" : "PAUSED", 50,
                 consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 30, 20,
                 simulationRunning ? GREEN : RED);

        DrawText("LMB - Add Source", 50,
                 consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 70, 16, DARKGRAY);
        DrawText("RMB - Add Wall", 50,
                 consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 90, 16, DARKGRAY);
        DrawText("MMB - Erase", 50,
                 consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 110, 16, DARKGRAY);

        if (!simulationRunning)
        {
            auto &cells = grid.getCells();
            float avgLeft = 0.0f, avgRight = 0.0f;
            int countLeft = 0, countRight = 0;

            for (int i = 1; i < consts::GRID_W - 1; i++)
            {
                for (int j = 1; j < consts::GRID_H - 1; j++)
                {
                    if (cells[i][j].get_state() != 1)
                    {
                        float c = cells[i][j].get_concentration();
                        if (i < consts::OBSTACLE_COL)
                        {
                            avgLeft += c;
                            countLeft++;
                        }
                        else if (i > consts::OBSTACLE_COL)
                        {
                            avgRight += c;
                            countRight++;
                        }
                    }
                }
            }
            if (countLeft > 0)
                avgLeft /= countLeft;
            if (countRight > 0)
                avgRight /= countRight;

            DrawText(TextFormat("Avg Left: %.3f", avgLeft), 50,
                     consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 140, 16, BLUE);
            DrawText(TextFormat("Avg Right: %.3f", avgRight), 50,
                     consts::PADDING_H + 3 * (consts::BUTTON_H + 20) + 160, 16, BLUE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}