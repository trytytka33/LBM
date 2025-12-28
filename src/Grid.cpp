#include "Grid.h"

Grid::Grid() : grid(consts::GRID_W, std::vector<Cell>(consts::GRID_H, Cell())) {};

std::vector<std::vector<Cell>> Grid::getGrid() const {
    return grid;
}   

void Grid::setGrid(int x, int y, int val) {
    if (x >= 0 && x < consts::GRID_W && y >= 0 && y < consts::GRID_H) {
        grid[x][y].set_state(val);
    }
}

/*void Grid::set_cell(int x , int y, int state){
    grid[x][y].set_state(state);
}
*/

int Grid::getWidth() const { 
    return static_cast<int>(grid.size()); 
}

int Grid::getHeight() const { 
    if (grid.empty()) {
        return 0;
    }
    return static_cast<int>(grid[0].size()); 
}

void Grid::reset() {
    for (int i = 0; i < consts::GRID_W; i++) {
        for (int j = 0; j < consts::GRID_H; j++) {
            if (i == 0 || i == consts::GRID_W - 1 || j == 0 || j == consts::GRID_H - 1) { 
                grid[i][j].set_state(consts::CELL_OBSTACLE);
            } else if (i == consts::OBSTACLE_COL && (j < consts::OBSTACLE_GAP_START || j > consts::OBSTACLE_GAP_END)) {
                grid[i][j].set_state(consts::CELL_OBSTACLE);
            } else {
                grid[i][j].set_state(consts::CELL_EMPTY);
            }
        }
    }
}

void Grid::initBorder() {
    for (int i = 0; i < consts::GRID_W; i++) {
        for (int j = 0; j < consts::GRID_H; j++) {
            if (i == 0 || i == consts::GRID_W - 1 || j == 0 || j == consts::GRID_H - 1) {
                grid[i][j].set_state(consts::CELL_OBSTACLE);
            }
        }
    }
}

void Grid::initObstacle() {
    for (int i = 0; i < consts::GRID_H; i++) {
        if (i < consts::OBSTACLE_GAP_START || i > consts::OBSTACLE_GAP_END) {
            grid[consts::OBSTACLE_COL][i].set_state(consts::CELL_OBSTACLE);
        } else {
            grid[consts::OBSTACLE_COL][i].set_state(consts::CELL_EMPTY);
        }
    }
}

const std::vector<Cell>& Grid::operator[](int index) const {
    return grid[index];
}

std::vector<Cell>& Grid::operator[](int index) {
    return grid[index];
}