#pragma once
#include <vector>
#include "constants.h"
#include "Cell.h"

class Grid {
private:
    std::vector<std::vector<Cell>> cells;

public:
    Grid();

    std::vector<std::vector<Cell>>& getCells();
    void setGrid(int x, int y, int val);
    Cell getCell();
    int getWidth() const;
    int getHeight() const;
    

    const std::vector<std::vector<Cell>>& getCells() const { 
        return cells; 
    }
    

    void reset();
    void initBorder();
    void initObstacle();
    void init_grid();
    const std::vector<Cell>& operator[](int index) const;
    std::vector<Cell>& operator[](int index);
};