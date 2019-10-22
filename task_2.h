//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TASK_2_H
#define LABARATORNAYA1_TASK_2_H

#include "matrix.h"

void Task_2(std::vector<std::vector<double>>& original_matrix) {
    Matrix U_matrix(original_matrix);
    size_t size = U_matrix.Size();
    std::vector<std::vector<double>> P_vectors;
    P_vectors.resize(size);
    for(int j = 0; j < size; ++j) {
        P_vectors[j].resize(size);
        for(int i = 0; i < size; ++i) {
            if(i == j) { P_vectors[j][i] = 1; }
        }
    }
    Matrix P_matrix(P_vectors);

    std::vector<std::vector<double>> L_vectors;
    L_vectors.resize(size);
    for(int j = 0; j < size; ++j) {
        L_vectors[j].resize(size);
        for(int i = 0; i < size; ++i) {
            if(i == j) { L_vectors[j][i] = 1; }
        }
    }
    Matrix L_matrix(L_vectors);

    for(size_t i = 0; i < U_matrix.Size(); ++i) {
        double max = fabs(U_matrix.Get()[i][i]);
        size_t the_number_of_line = i;
        for(size_t j = i + 1; j < U_matrix.Size(); ++j) {
            if(max < fabs(U_matrix.Get()[j][i])) {
                max = U_matrix.Get()[j][i];
                the_number_of_line = j;
            }
        }
        if(the_number_of_line != i) {
            U_matrix.SwapTwoLines(i, the_number_of_line);
            P_matrix.SwapTwoLines(i, the_number_of_line);
        }
        for(size_t j = i + 1; j < U_matrix.Size(); ++j) {
            double factor = U_matrix.Get()[j][i] / U_matrix.Get()[i][i];
            U_matrix.LinesSubstraction(j, i, factor);
            L_matrix.SetElement(j, i, factor);
            std::cout << L_matrix << U_matrix;
        }
    }
    std::cout << L_matrix << U_matrix << P_matrix;
}

#endif //LABARATORNAYA1_TASK_2_H
