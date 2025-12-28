#include "Simulation.h"

void calculate_concentration(double* concentration,int num_of_directions, std::vector<int> f_distribution){
        for(int i = 0; i < num_of_directions; i++){
            *concentration+=f_distribution[i];
        }
}