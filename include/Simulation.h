#pragma once
#include <vector>
#include <iostream>
#include "constants.h"
#include "Cell.h"

class Simulation{
    public:
    void calculate_concentration(double& concentration, float f_distribution[]);
    void collision(Cell& cell, float tau, float t);   
    void streaming(std::vector<std::vector<Cell>>& grid);
};