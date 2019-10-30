//
// Created by sasha on 30/10/19.
//

#ifndef LABARATORNAYA1_TASK_3_H
#define LABARATORNAYA1_TASK_3_H

#include "matrix.h"

void Task_3(std::vector<std::vector<double>>& P_matrix, std::vector<std::vector<double>>& L_matrix,
            std::vector<std::vector<double>>& U_matrix, std::vector<std::vector<double>>& values,
            std::vector<std::vector<double>>& LLT_matrix, std::vector<size_t>& D_matrix, std::vector<std::vector<double>>& values_for_LDLT) {
    for(size_t i = 0; i < U_matrix.size(); ++i) {
        for(size_t j = i + 1; j < U_matrix.size(); ++j) {
            double factor = U_matrix[j][i] / U_matrix[i][i];
            LinesSubstraction(U_matrix, j, i, factor);
            L_matrix[j][i] = factor;
            factor = LLT_matrix[j][i] / LLT_matrix[i][i];
            LinesSubstraction(LLT_matrix, j, i, factor);
        }
        L_matrix[i][i] =  1;
        if(LLT_matrix[i][i] < 0) {
            D_matrix.push_back(i);
            LLT_matrix[i][i] = -LLT_matrix[i][i];
        }
        double sqrt = std::sqrt(LLT_matrix[i][i]);
        for(size_t j = i; j < LLT_matrix.size(); ++j) {
            LLT_matrix[i][j] /= sqrt;
        }
    }

    for(size_t i = 0; i < L_matrix.size(); ++i) {
        for(size_t j = i + 1; j < L_matrix.size(); ++j) {
            if(L_matrix[j][i] == 0) {
                continue;
            }
            double factor = L_matrix[j][i];
            LinesSubstraction(values, j, i, factor);
        }
    }

    for(int i = static_cast<int>(U_matrix.size() - 1); i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            if(U_matrix[j][i] == 0) {
                continue;
            }
            double factor = U_matrix[j][i] / U_matrix[i][i];
            LinesSubstraction(values, static_cast<size_t>(j), static_cast<size_t>(i), factor);
        }
        double to_unit = U_matrix[i][i];
        for(auto& element : values[i]) {
            element /= to_unit;
        }
    }
}


#endif //LABARATORNAYA1_TASK_3_H
