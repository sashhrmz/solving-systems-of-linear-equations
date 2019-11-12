//
// Created by sasha on 30/10/19.
//

#ifndef LABARATORNAYA1_TASK_3_H
#define LABARATORNAYA1_TASK_3_H

#include "matrix.h"

void GaussForLUWhithoutPermetations(std::vector<std::vector<double>>& L_matrix, std::vector<std::vector<double>>& U_matrix,
                                    std::vector<std::vector<double>>& values) {
    for(size_t i = 0; i < L_matrix.size(); ++i) {
        for(size_t j = i + 1; j < L_matrix.size(); ++j) {
            if(L_matrix[j][i] == 0) {
                continue;
            }
            values[j][0] -= values[i][0] * L_matrix[j][i];
        }
    }

    for(int i = U_matrix.size() - 1; i >= 0; --i) {
        double to_unit = U_matrix[i][i];
        for(int j = i - 1; j >= 0; --j) {
            if(U_matrix[j][i] == 0) {
                continue;
            }
            values[j][0] -= values[i][0] * U_matrix[j][i] / to_unit;
        }
        values[i][0] /= to_unit;
    }
}

void Task_3_LU(std::vector<std::vector<double>>& L_matrix, std::vector<std::vector<double>>& U_matrix,
               std::vector<std::vector<double>>& values) {
    for(size_t i = 0; i < U_matrix.size(); ++i) {
        for(size_t j = i + 1; j < U_matrix.size(); ++j) {
            double factor = U_matrix[j][i] / U_matrix[i][i];
            for(size_t k = i + 1; k < U_matrix.size(); ++k) {
                U_matrix[j][k] -= factor * U_matrix[i][k];
            }
            L_matrix[j][i] = factor;
        }
        L_matrix[i][i] =  1;
    }
    GaussForLUWhithoutPermetations(L_matrix, U_matrix, values);
}

void GaussForLDLT(std::vector<std::vector<double>>& L_matrix, std::vector<std::vector<double>>& LT_matrix,
                  std::vector<size_t>& D_matrix, std::vector<std::vector<double>>& values) {
    for(size_t i = 0; i < LT_matrix.size(); ++i) {
        double to_unit = LT_matrix[i][i];
        for(size_t j = i + 1; j < LT_matrix.size(); ++j) {
            if(LT_matrix[j][i] == 0) {
                continue;
            }
            values[j][0] -= values[i][0] * LT_matrix[j][i] / to_unit;
        }
        values[i][0] /= to_unit;
    }

    for(auto el : D_matrix) {
        values[el][0] *= (-1);
    }

    for(int i = L_matrix.size() - 1; i >= 0; --i) {
        double to_unit = L_matrix[i][i];
        for(int j = i - 1; j >= 0; --j) {
            if(L_matrix[j][i] == 0) {
                continue;
            }
            values[j][0] -= values[i][0] * L_matrix[j][i] / to_unit;
        }
        values[i][0] /= to_unit;
    }
}

void Task_3_LDLT(std::vector<std::vector<double>>& L_matrix, std::vector<std::vector<double>>& LT_matrix,
        std::vector<size_t>& D_matrix, std::vector<std::vector<double>>& values) {
    double factor;
    double sqr;
    for (size_t i = 0; i < L_matrix.size(); ++i) {
        for (size_t j = i + 1; j < L_matrix.size(); ++j) {
            factor = L_matrix[i][j] / L_matrix[i][i];
            for (size_t k = j; k < L_matrix.size(); ++k) {
                L_matrix[j][k] -= L_matrix[i][k] * factor;
            }
         }

        if (L_matrix[i][i] < 0) {
            D_matrix.push_back(i);
            sqr = -std::sqrt(-L_matrix[i][i]);
        } else {
            sqr = std::sqrt(L_matrix[i][i]);
        }
        for(size_t j = i; j < L_matrix.size(); ++j) {
            L_matrix[i][j] /= sqr;
            LT_matrix[j][i] += L_matrix[i][j];
        }
    }
    GaussForLDLT(L_matrix, LT_matrix, D_matrix, values);
}

#endif //LABARATORNAYA1_TASK_3_H
