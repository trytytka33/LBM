#pragma once
#include <vector>
#include "constants.h"
#include "Cell.h"

class Grid {
private:
    std::vector<std::vector<Cell>> grid;

public:
    Grid();

    std::vector<std::vector<Cell>> getGrid() const;
    void setGrid(int x, int y, int val);
    Cell getCell();
    int getWidth() const;
    int getHeight() const;
    
    //void set_cell(int x , int y, int state); 

    void reset();
    void initBorder();
    void initObstacle();
    void init_grid();
    const std::vector<Cell>& operator[](int index) const;
    std::vector<Cell>& operator[](int index);
};