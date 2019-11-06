//
// Created by sasha on 04/11/19.
//

#ifndef LABARATORNAYA1_TASK_4_H
#define LABARATORNAYA1_TASK_4_H

#include "matrix.h"

void Task_4(std::vector<std::vector<double>>& matrix, std::vector<double>& values) {
    for(size_t i = 0; i < matrix.size() - 1; ++i) {
        int j = 2;
        if (i == 0) {
            j = 1;
        }
        values[i] /= matrix[i][j - 1];
        matrix[i][j] /= matrix[i][j - 1];
        matrix[i + 1][1] -= matrix[i][j] * matrix[i + 1][0];
        values[i + 1] -= values[i] * matrix[i + 1][0];
    }
    for(int i = static_cast<int>(matrix.size() - 1); i > 0; --i) {
        if (i == matrix.size() - 1) {
            values[i] /= matrix[i][1];
        } else {
            values[i] -= values[i + 1] * matrix[i][2];

        }
    }
    values[0] -= values[1] * matrix[0][1];
}

#endif //LABARATORNAYA1_TASK_4_H
