//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TASK_2_H
#define LABARATORNAYA1_TASK_2_H

#include "matrix.h"

void Task_2(std::vector<std::vector<double>>& P_matrix, std::vector<std::vector<double>>& L_matrix,
        std::vector<std::vector<double>>& U_matrix, std::vector<std::vector<double>>& values) {
    for(size_t i = 0; i < U_matrix.size(); ++i) {
        double max = fabs(U_matrix[i][i]);
        size_t the_number_of_line = i;
        for(size_t j = i + 1; j < U_matrix.size(); ++j) {
            if(max < fabs(U_matrix[j][i])) {
                max = fabs(U_matrix[j][i]);
                the_number_of_line = j;
            }
        }
        if(the_number_of_line != i) {
            U_matrix[i].swap(U_matrix[the_number_of_line]);
            P_matrix[i].swap(P_matrix[the_number_of_line]);
            L_matrix[i].swap(L_matrix[the_number_of_line]);
            values[i].swap(values[the_number_of_line]);
        }
        for(size_t j = i + 1; j < U_matrix.size(); ++j) {
            double factor = U_matrix[j][i] / U_matrix[i][i];
            LinesSubstraction(U_matrix, j, i, factor);
            L_matrix[j][i] = factor;
        }
        L_matrix[i][i] =  1;
    }

    for(size_t i = 0; i < L_matrix.size(); ++i) {
        for(size_t j = i + 1; j < L_matrix.size(); ++j) {
            if(L_matrix[j][i] == 0) {
                continue;
            }
            double factor = L_matrix[j][i];
            //LinesSubstraction(L_matrix, j, i, factor);
            LinesSubstraction(values, j, i, factor);
        }
    }

    for(int i = static_cast<int>(U_matrix.size() - 1); i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            if(U_matrix[j][i] == 0) {
                continue;
            }
            double factor = U_matrix[j][i] / U_matrix[i][i];
            //LinesSubstraction(U_matrix, static_cast<size_t>(j), static_cast<size_t>(i), factor);
            LinesSubstraction(values, static_cast<size_t>(j), static_cast<size_t>(i), factor);
        }
        double to_unit = U_matrix[i][i];
       // U_matrix[i][i] /= to_unit;
        for(auto& element : values[i]) {
            element *= to_unit;
        }
    }
}

#endif //LABARATORNAYA1_TASK_2_H
