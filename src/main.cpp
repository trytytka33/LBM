#include "raylib.h"
#include "constants.h"
#include "Grid.h"
#include "Button.h"
#include "Renderer.h"
#include "InputHandler.h"
#include <iostream>

int main() {
    const char* title = "LBM Simulation";
    InitWindow(consts::WINDOW_W, consts::WINDOW_H, title);
    SetTargetFPS(60); 
    
    Grid grid;
    grid.initBorder();
    grid.initObstacle();
    
    Button startButton(50, consts::PADDING_H, 
                      consts::BUTTON_W, consts::BUTTON_H, "Start");
    Button clearButton(50, consts::PADDING_H + consts::BUTTON_H + 20, 
                      consts::BUTTON_W, consts::BUTTON_H, "Clear");
    
    bool simulationRunning = false;
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Renderer::drawGrid();
        Renderer::drawGridWithColors(grid);
        
        if (startButton.isPressed()) {
            simulationRunning = !simulationRunning;
            std::cout << (simulationRunning ? "Simulation started" : "Simulation paused") 
                     << std::endl;
        }
        if (clearButton.isPressed()) {
            simulationRunning = false;
            grid.reset();
            std::cout << "Grid cleared" << std::endl;
        }
        
        if (!simulationRunning) {
            InputHandler::handleMouseInput(grid);
        }
        
        // TODO: Add LBM simulation step here when simulationRunning == true
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}