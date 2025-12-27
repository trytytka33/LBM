#pragma once

namespace consts {
    // Grid settingss
    constexpr int CELL_SIZE = 5;
    constexpr int GRID_W = 250;     
    constexpr int GRID_H = 150;    

    constexpr int PADDING_W = 250;
    constexpr int PADDING_H = 150;
    constexpr int PADDING_LEFT = 300;
    constexpr int PADDING_RIGHT = 150;

    // Window dims
    constexpr int WINDOW_W = GRID_W * CELL_SIZE + 2 * PADDING_W + 150;  
    constexpr int WINDOW_H = GRID_H * CELL_SIZE + 2 * PADDING_H + 50;  

    // Button 
    constexpr int BUTTON_W = 150;
    constexpr int BUTTON_H = 50;

    // Obstacle 
    constexpr int OBSTACLE_GAP_SIZE = 30;
    constexpr int OBSTACLE_GAP_START = 40;
    constexpr int OBSTACLE_GAP_END = OBSTACLE_GAP_SIZE + OBSTACLE_GAP_START;
    constexpr int OBSTACLE_COL = 70;

    // cell types 
    constexpr int CELL_EMPTY = 0;
    constexpr int CELL_FLUID = 1;
    constexpr int CELL_OBSTACLE = 2;
}