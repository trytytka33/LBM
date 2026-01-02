#include "Grid.h"

Grid::Grid() : cells(consts::GRID_W, std::vector<Cell>(consts::GRID_H, Cell()))
{
    init_grid();
}

std::vector<std::vector<Cell>> &Grid::getCells()
{
    return cells;
}

void Grid::init_grid()
{
    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            cells[i][j].set_state(0);
            cells[i][j].set_concentration(0.0f);

            float *f_in = cells[i][j].get_f_in();
            float *f_out = cells[i][j].get_f_out();
            for (int k = 0; k < 4; k++)
            {
                f_in[k] = 0.0f;
                f_out[k] = 0.0f;
            }
        }
    }
    initBorder();
    initObstacle();

    for (int i = 1; i < consts::GRID_W - 1; i++)
    {
        for (int j = 1; j < consts::GRID_H - 1; j++)
        {
            if (cells[i][j].get_state() != 1)
            {
                float initial_conc = 0.0f;

                if (i < consts::OBSTACLE_COL)
                {

                    initial_conc = 1.0f;
                }
                else if (i > consts::OBSTACLE_COL)
                {

                    initial_conc = 0.0f;
                }
                else
                {

                    initial_conc = 0.5f;
                }

                cells[i][j].set_concentration(initial_conc);
                float *f_in = cells[i][j].get_f_in();
                float *f_out = cells[i][j].get_f_out();
                float *f_eq = cells[i][j].get_f_eq();

                for (int k = 0; k < 4; k++)
                {
                    f_in[k] = consts::weighting_coefficient_D2Q4 * initial_conc;
                    f_out[k] = consts::weighting_coefficient_D2Q4 * initial_conc;
                    f_eq[k] = consts::weighting_coefficient_D2Q4 * initial_conc;
                }
            }
        }
    }
}

void Grid::reset()
{
    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            cells[i][j].set_state(0);
            cells[i][j].set_concentration(0.0f);

            float *f_in = cells[i][j].get_f_in();
            float *f_out = cells[i][j].get_f_out();
            for (int k = 0; k < 4; k++)
            {
                f_in[k] = 0.0f;
                f_out[k] = 0.0f;
            }
        }
    }
    initBorder();
}

void Grid::initBorder()
{
    for (int i = 0; i < consts::GRID_W; i++)
    {
        for (int j = 0; j < consts::GRID_H; j++)
        {
            if (i == 0 || i == consts::GRID_W - 1 || j == 0 || j == consts::GRID_H - 1)
            {
                cells[i][j].set_state(1);
            }
        }
    }
}

void Grid::initObstacle()
{

    for (int j = 0; j < consts::GRID_H; j++)
    {
        if (j < consts::OBSTACLE_GAP_START || j > consts::OBSTACLE_GAP_END)
        {
            cells[consts::OBSTACLE_COL][j].set_state(1);
        }
    }
}