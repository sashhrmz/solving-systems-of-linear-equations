//
// Created by sasha on 04/11/19.
//

#ifndef LABARATORNAYA1_TASK_4_H
#define LABARATORNAYA1_TASK_4_H

#include "matrix.h"

void Task_4(std::vector<std::vector<double>>& matrix, std::vector<double>& values) {
    for(size_t i = 0; i < matrix.size() - 1; ++i) {
        if(fabs(matrix[i][0]) < fabs(matrix[i + 1][0])) {
            matrix[i].swap(matrix[i + 1]);
            std::swap(values[i], values[i + 1]);
            if(i == matrix.size() - 2) {
                matrix[i].push_back(0);
            }
        }
        values[i] /= matrix[i][0];
        matrix[i][1] /= matrix[i][0];
        matrix[i][2] /= matrix[i][0];
        double t = matrix[i + 1][0];
        values[i + 1] -= values[i] * t;
        matrix[i + 1][0] = matrix[i + 1][1] - matrix[i][1] * t;
        if(i != matrix.size() - 2) {
            matrix[i + 1][1] = matrix[i + 1][2] - t * matrix[i][2];
            matrix[i + 1][2] = 0;
        } else {
            matrix[i + 1][1] = 0;
            values[i + 1] /= matrix[i + 1][0];
        }
    }
    for(int i = static_cast<int>(matrix.size() - 1); i > 0; --i) {
        values[i - 1] -= values[i] * matrix[i - 1][1];
        if(i > 1) {
            values[i - 2] -= values[i] * matrix[i - 2][2];
        }
    }
}

#endif //LABARATORNAYA1_TASK_4_H
