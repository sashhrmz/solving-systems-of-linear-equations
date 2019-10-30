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

void LinesSubstraction(std::vector<std::vector<double>>& matrix_, size_t the_number_of_minued_line,
                       size_t the_number_of_subtrahend_line, double the_multiplied_number = 1) {
    for(size_t i = 0; i < std::min(matrix_[the_number_of_minued_line].size(), matrix_[the_number_of_subtrahend_line].size()); ++i) {
        matrix_[the_number_of_minued_line][i] -= the_multiplied_number * matrix_[the_number_of_subtrahend_line][i];
    }
}

#endif //LABARATORNAYA1_MATRIX_H
