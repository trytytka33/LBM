#pragma once
#include "Grid.h"

class Renderer {
public:
    static void drawGrid();
    static void drawGridWithColors(const Grid& grid);
};