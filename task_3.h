//
// Created by sasha on 30/10/19.
//

#ifndef LABARATORNAYA1_TASK_3_H
#define LABARATORNAYA1_TASK_3_H

#include "matrix.h"

void Task_3_LU(std::vector<std::vector<double>>& P_matrix, std::vector<std::vector<double>>& L_matrix,
            std::vector<std::vector<double>>& U_matrix, std::vector<std::vector<double>>& values) {
    for(size_t i = 0; i < U_matrix.size(); ++i) {
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

void Task_3_LDLT(std::vector<std::vector<double>>& L_matrix, std::vector<std::vector<double>>& LT_matrix,
        std::vector<std::vector<size_t>>& D_matrix, std::vector<std::vector<double>>& values) {
    double factor;
    double sqr;
    for (int i = 0; i < L_matrix.size(); ++i) {
        for (int j = i + 1; j < L_matrix.size(); ++j) {
            factor = L_matrix[i][j] / L_matrix[i][i];
            if (L_matrix[i][i] < 0) {
                D_matrix[0].push_back(i);
                sqr = -std::sqrt(-L_matrix[i][i]);
            } else {
                sqr = std::sqrt(L_matrix[i][i]);
            }
            for (int k = i; k < L_matrix.size(); ++k) {
                L_matrix[j][k] -= L_matrix[i][k] * factor;
                L_matrix[i][k] /= sqr;
                LT_matrix[k][i] = L_matrix[i][k];
            }
        }
    }
     if(L_matrix[L_matrix.size() - 1][L_matrix.size() - 1] < 0) {
        D_matrix[0].push_back(L_matrix.size() - 1);
        sqr = -std::sqrt(-L_matrix[L_matrix.size() - 1][L_matrix.size() - 1]);
     } else {
        sqr = std::sqrt(L_matrix[L_matrix.size() - 1][L_matrix.size() - 1]);
     }
   L_matrix[L_matrix.size() - 1][L_matrix.size() - 1] /= sqr;
    LT_matrix[L_matrix.size() - 1][L_matrix.size() - 1] = L_matrix[L_matrix.size() - 1][L_matrix.size() - 1];

    for(size_t i = 0; i < LT_matrix.size(); ++i) {
        for(size_t j = i + 1; j < LT_matrix.size(); ++j) {
            if(LT_matrix[j][i] == 0) {
                continue;
            }
            double factor = LT_matrix[j][i] / LT_matrix[i][i];
            LinesSubstraction(values, j, i, factor);
        }
        double to_unit = LT_matrix[i][i];
        for(auto& element : values[i]) {
            element /= to_unit;
        }
    }

    for(auto el : D_matrix[0]) {
        values[el][0] *= (-1);
    }

    for(int i = static_cast<int>(L_matrix.size() - 1); i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            if(L_matrix[j][i] == 0) {
                continue;
            }
            double factor = L_matrix[j][i] / L_matrix[i][i];
            LinesSubstraction(values, static_cast<size_t>(j), static_cast<size_t>(i), factor);
        }
        double to_unit = L_matrix[i][i];
        for(auto& element : values[i]) {
            element /= to_unit;
        }
    }
}

#endif //LABARATORNAYA1_TASK_3_H