//
// Created by sasha on 15/10/19.
//

#ifndef LABARATORNAYA1_TASK_1_H
#define LABARATORNAYA1_TASK_1_H

#include "matrix.h"

void Task_1(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& result_vectors) {

    for (size_t i = matrix.size() - 1; i > 0; --i) {
        if (fabs(matrix[i][i]) < fabs(matrix[i - 1][i])) {
            matrix[i].swap(matrix[i - 1]);
            result_vectors[i].swap(result_vectors[i - 1]);
        }
        if (matrix[i - 1][i] == 0) {
            continue;
        }
        double factor = (matrix[i - 1][i]) / (matrix[i][i]);

        LinesSubstraction(matrix, i - 1, i, factor);
        for(size_t j = 0; j < matrix.size(); ++j) {
            result_vectors[i - 1][j] -= factor * result_vectors[i][j];
        }
    }

    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] == 0) {
            std::cout << "there is no inverse matrix (first task)";
            return;
        }
        for (size_t j = i + 1; j < matrix.size(); ++j) {
            if (matrix[j][i] == 0) {
                continue;
            }
            LinesSubstraction(result_vectors, j, i, matrix[j][i] / matrix[i][i]);
        }
        for(int j = 0; j < matrix.size(); ++j) {
            result_vectors[i][j] /= matrix[i][i];
        }
    }
}

#endif //LABARATORNAYA1_TASK_1_H

