//
// Created by sasha on 15/10/19.
//

#ifndef LABARATORNAYA1_TASK_1_H
#define LABARATORNAYA1_TASK_1_H

#include "matrix.h"

void Task_1(std::vector<std::vector<double>>& original_matrix) {
    Matrix matrix(original_matrix);
    size_t size = matrix.Size();
    std::vector<std::vector<double>> result_vectors;
    result_vectors.resize(size);
    for(int j = 0; j < size; ++j) {
        if (matrix.Get()[j][j] == 0) {
            std::cout << "there is no inverse matrix" << std::endl;
            return;
        }
        result_vectors[j].resize(size);
        for(int i = 0; i < size; ++i) {
            if(i == j) { result_vectors[j][i] = 1; }
        }
    }

    Matrix result_matrix(result_vectors);

    for(size_t i = size - 1; i > 0; --i) {
        if(fabs(matrix.Get()[i][i])  < fabs(matrix.Get()[i - 1][i])) {
            matrix.SwapTwoLines(i, i - 1);
            result_matrix.SwapTwoLines(i, i - 1);
        }
        if(matrix.Get()[i - 1][i] == 0) {
            continue;
        }
          double factor = (matrix.Get()[i - 1][i]) / (matrix.Get()[i][i]);
          matrix.LineMultiply(factor, i);
          result_matrix.LineMultiply(factor, i);

          matrix.LinesSubstraction(i - 1, i);
          result_matrix.LinesSubstraction(i - 1, i);
    }

    for(size_t i = 0; i < matrix.Size(); ++i) {
        for(size_t j = i + 1; j < matrix.Size(); ++j) {
            if(matrix.Get()[j][i] == 0) {
                continue;
            }
            double factor = matrix.Get()[j][i] / matrix.Get()[i][i];
            matrix.LineMultiply(factor, i);
            result_matrix.LineMultiply(factor, i);

            matrix.LinesSubstraction(j, i);
            result_matrix.LinesSubstraction(j, i);
        }
        double to_unit = matrix.Get()[i][i];
        result_matrix.DivideElement(to_unit, i, i);
    }

    std::cout << result_matrix;
    std::cout << matrix;
}

#endif //LABARATORNAYA1_TASK_1_H

