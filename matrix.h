//
// Created by sasha on 15/10/19.
//

#ifndef LABARATORNAYA1_MATRIX_H
#define LABARATORNAYA1_MATRIX_H

#include <vector>
#include <iostream>
#include <istream>
#include <cmath>
#include <algorithm>
#include <fstream>

template <typename T>
void ReadMatrix(std::vector<std::vector<T>>& matrix, const std::string& name) {
    std::ifstream fin(name);
    double el;
    int n;
    fin >> n;
    matrix.resize(n);
    for(int i = 0; i < n; ++i) {
        fin.get();
        for(int j = 0; j < 4; ++j) {
            fin >> el;
            matrix[i].push_back(el);
        }
    }
}

template <typename T>
void ReadVector(std::vector<T>& values, const std::string& name) {
    std::ifstream fin(name);
    double el;
    int n;
    fin >> n;
    values.resize(n);
    for(int i = 0; i < n; ++i) {
        fin >> values[i];
    }
}

template <typename T>
void ReadMatrixWithValues(std::vector<std::vector<T>>& matrix, std::vector<T>& values, const std::string& name) {
    std::ifstream fin(name);
    double el;
    int n;
    fin >> n;
    matrix.resize(n);
    for(int i = 0; i < n; ++i) {
        fin.get();
        for(int j = 0; fin.peek() != '\n'; ++j) {
            fin >> el;
            matrix[i].push_back(el);
        }
    }
    values.resize(n);
    for(int i = 0; i < n; ++i) {
        fin >> values[i];
    }
}

void LinesSubstraction(std::vector<std::vector<double>>& matrix_, size_t the_number_of_minued_line,
                       size_t the_number_of_subtrahend_line, double the_multiplied_number = 1) {
    for(size_t i = 0; i < std::min(matrix_[the_number_of_minued_line].size(), matrix_[the_number_of_subtrahend_line].size()); ++i) {
        matrix_[the_number_of_minued_line][i] -= the_multiplied_number * matrix_[the_number_of_subtrahend_line][i];
    }
}

#endif //LABARATORNAYA1_MATRIX_H
