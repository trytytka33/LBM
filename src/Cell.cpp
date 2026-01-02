#include "Cell.h"

Cell::Cell(int x, int y, int s, float C) : x(x), y(y), state(s), concentration(C) {
    for(int i = 0; i < 4; i++) {
        f_in[i] = 0.0f;
        f_out[i] = 0.0f;
        f_eq[i] = 0.0f;
    }
}

int Cell::get_x() const { 
    return x;  
}

int Cell::get_y() const { 
    return y; 
}

int Cell::get_state() const { 
    return state; 
}

float Cell::get_concentration() const { 
    return concentration; 
}


void Cell::set_x(int newX) { 
    x = newX; 
}

void Cell::set_y(int newY) { 
    y = newY; 
}

void Cell::set_state(int s) { 
    state = s; 
}

void Cell::set_concentration(float C) { 
    concentration = C; 
}