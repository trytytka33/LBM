#pragma once
#include <vector>
#include "constants.h"

class Grid {
private:
    std::vector<std::vector<int>> grid;

public:
    Grid();
    
    std::vector<std::vector<int>> getGrid() const;
    void setGrid(int x, int y, int val);
    
    int getWidth() const;
    int getHeight() const;
    
    void reset();
    void initBorder();
    void initObstacle();
    
    const std::vector<int>& operator[](int index) const;
    std::vector<int>& operator[](int index);
};