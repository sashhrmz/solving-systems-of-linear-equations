//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TASK_2_H
#define LABARATORNAYA1_TASK_2_H

#include "matrix.h"

Matrix MultiplyMatrix(std::vector<std::vector<double>> first, std::vector<std::vector<double>> second) {
    std::vector<std::vector<double>> matrix;
    for(int i = 0; i < first.size(); ++i) {
        if(second.size() != first[i].size()) {
            Matrix res(matrix);
            return res;
        }
    }
    for(size_t i = 0; i < first.size(); ++i) {
        std::vector<double> line;
        for(size_t j = 0; j < second[0].size(); j++) {
            double t = 0;
            for(size_t k = 0; k < second.size(); ++k) {
                t += first[i][k] * second[k][j];
            }
            line.push_back(t);
            t = 0;
        }
        matrix.push_back(line);
        line.clear();
    }
    Matrix result(matrix);
    return result;
}

void Task_2(std::vector<std::vector<double>>& original_matrix, std::vector<std::vector<double>> values) {
    Matrix U_matrix(original_matrix);
    Matrix value_matrix(values);

    size_t size = U_matrix.Size();
    std::vector<std::vector<double>> L_vectors;
    L_vectors.resize(size);
    for(int j = 0; j < size; ++j) {
        L_vectors[j].resize(size);
    }
    Matrix L_matrix(L_vectors);

    std::vector<std::vector<double>> P_vectors;
    P_vectors.resize(size);
    for(int j = 0; j < size; ++j) {
        P_vectors[j].resize(size);
        for(int i = 0; i < size; ++i) {
            if(i == j) { P_vectors[j][i] = 1; }
        }
    }
    Matrix P_matrix(P_vectors);

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
            L_matrix.SwapTwoLines(i, the_number_of_line);
            value_matrix.SwapTwoLines(i, the_number_of_line);
        }
        for(size_t j = i + 1; j < U_matrix.Size(); ++j) {
            double factor = U_matrix.Get()[j][i] / U_matrix.Get()[i][i];
            U_matrix.LinesSubstraction(j, i, factor);
            L_matrix.SetElement(j, i, factor);
        }
        L_matrix.SetElement(i, i, 1);
    }

    for(size_t i = 0; i < L_matrix.Size(); ++i) {
        for(size_t j = i + 1; j < L_matrix.Size(); ++j) {
            if(L_matrix.Get()[j][i] == 0) {
                continue;
            }
            double factor = L_matrix.Get()[j][i];
            L_matrix.LinesSubstraction(j, i, factor);
            value_matrix.LinesSubstraction(j, i, factor);
        }
    }

    for(int i = static_cast<int>(U_matrix.Size() - 1); i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            if(U_matrix.Get()[j][i] == 0) {
                continue;
            }
            double factor = U_matrix.Get()[j][i] / U_matrix.Get()[i][i];
            U_matrix.LinesSubstraction(static_cast<size_t>(j), static_cast<size_t>(i), factor);
            value_matrix.LinesSubstraction(static_cast<size_t>(j), static_cast<size_t>(i), factor);
        }
        double to_unit = U_matrix.Get()[i][i];
        U_matrix.DivideElement(to_unit, static_cast<size_t>(i), static_cast<size_t>(i));
        value_matrix.LineMultiply((1 / to_unit), static_cast<size_t>(i));
    }
    std::cout << U_matrix << value_matrix;
}

#endif //LABARATORNAYA1_TASK_2_H
