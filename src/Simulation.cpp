#include "Simulation.h"
#include "Cell.h"
#include "Grid.h"

void calculate_concentration(double &concentration, float f_distribution[]){
        for(int i = 0; i < consts::num_of_directions; i++){
            concentration+= f_distribution[i];
        }
    }
void collision(Cell& cell, float tau = 1.0, float t = 1){
    float C = 0;
    float* f_in = cell.get_f_in();
    for(int i = 0; i < consts::num_of_directions; i++){
        C += f_in[i];
    }
    cell.set_concentration(C);
    float* f_eq = cell.get_f_eq();
    for(int i = 0; i < 4; i++){
        f_in[i] = consts::weighting_coefficient_D2Q4 * cell.get_concentration();
    }
    float* f_out = cell.get_f_out();
    for(int i = 0; i < consts::num_of_directions; i++){
        f_out[i] = f_in[i] + t * (f_eq[i] - f_in[i])/tau;
    }
}
void streaming(std::vector<std::vector<Cell>> &grid){
    auto temp_grid = grid;
    for(int i = 0; i < consts::GRID_W; i++){
        for(int j = 0; j < consts::GRID_H; j++){
            float* f_in = grid[i][j].get_f_in();
            float* f_out = grid[i][j].get_f_out();
            for(int k = 0; k < 4; k++){
                int sasiadX = i - Cell::dx[i];
                int sasiadY = j - Cell::dy[j]; // kierunek z ktorego przyszla czastla 
            }
        }
    }
    
}
