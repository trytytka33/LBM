#pragma once
#include <iostream>
#include <vector>
#include <utility>

class Cell {
private: 
    int x, y, state;
    float concentration; 
    float f_in[4];   
    float f_out[4];
    float f_eq[4];
    
    static const int dx[4];  // {1, 0, -1, 0}
    static const int dy[4];  // {0, 1, 0, -1}
    
public:
    // Konstruktor
    Cell(int x = 0, int y = 0, int s = 0, float C = 0.0);
    
    int get_x() const;
    int get_y() const;
    int get_state() const;
    float get_concentration() const;
    

    float* get_f_in() { return f_in; }
    float* get_f_out() { return f_out; }
    float* get_f_eq() { return f_eq; }
    
    const float* get_f_in() const { return f_in; }
    const float* get_f_out() const { return f_out; }
    const float* get_f_eq() const { return f_eq; }

    void set_x(int newX);
    void set_y(int newY);
    void set_state(int s);
    void set_concentration(float C);
    

    Cell& operator=(int s) { 
        state = s; 
        return *this;
    }
    
    bool operator==(int val) const {
        return state == val;
    }
    static int get_dx(int i) { return dx[i]; }
    static int get_dy(int i) { return dy[i]; }
};