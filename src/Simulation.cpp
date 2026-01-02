#include "Simulation.h"
#include "Cell.h"
#include "Grid.h"

void Simulation::collision(Cell &cell, float tau, float t)
{
    if (cell.get_state() == 1)
        return;

    float C = 0.0f;
    float *f_in = cell.get_f_in();
    for (int i = 0; i < 4; i++)
    {
        C += f_in[i];
    }
    cell.set_concentration(C);

    float *f_out = cell.get_f_out();
    float *f_eq = cell.get_f_eq();

    for (int i = 0; i < 4; i++)
    {
        f_eq[i] = consts::weighting_coefficient_D2Q4 * C;
    }

    for (int i = 0; i < 4; i++)
    {
        f_out[i] = f_in[i] + (t / tau) * (f_eq[i] - f_in[i]);
    }
}

void Simulation::streaming(std::vector<std::vector<Cell>> &grid)
{
    auto temp_grid = grid;

    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            float *f_in_temp = temp_grid[i][j].get_f_in();
            for (int k = 0; k < 4; k++)
            {
                f_in_temp[k] = 0.0f;
            }
        }
    }
    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            if (grid[i][j].get_state() == 1)
                continue;

            float *f_out = grid[i][j].get_f_out();

            for (int k = 0; k < 4; k++)
            {
                int nx = i + Cell::dx[k];
                int ny = j + Cell::dy[k];

                if (nx >= 0 && nx < consts::GRID_W &&
                    ny >= 0 && ny < consts::GRID_H &&
                    grid[nx][ny].get_state() != 1)
                {
                    temp_grid[nx][ny].get_f_in()[k] += f_out[k];
                }
                else
                {
                    int rev = (k + 2) % 4;
                    temp_grid[i][j].get_f_in()[rev] += f_out[k];
                }
            }
        }
    }
    grid = temp_grid;
}