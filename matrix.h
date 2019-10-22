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

class Matrix {

public:

    Matrix(std::vector<std::vector<double>>& matrix) : matrix_(matrix) {
        size_t size_ = matrix_.size();
    }

    friend std::ostream& operator<<(std::ostream& input, const Matrix& matrix) {
        for(auto vec : matrix.Get()) {
            for(auto el : vec) {
                input << el << " ";
            }
            input << std::endl;
        }
        input << std::endl;
        return input;
    }

    size_t Size(int i = -1) const {
        if(i == -1) { return matrix_.size(); }
        else { return matrix_[i].size(); }
    }

    std::vector<std::vector<double>> Get() const { return matrix_; }

    void LineMultiply(double multiply_number, size_t the_line_num) {
        for(auto& element : matrix_[the_line_num]) {
            element *= multiply_number;
        }
    }

    void LinesSubstraction(size_t the_number_of_minued_line, size_t the_number_of_subtrahend_line, double the_multiplied_number = 1) {
        for(size_t i = 0; i < std::min(matrix_[the_number_of_minued_line].size(), matrix_[the_number_of_subtrahend_line].size()); ++i) {
            matrix_[the_number_of_minued_line][i] -= the_multiplied_number * matrix_[the_number_of_subtrahend_line][i];
        }
    }

    void DivideElement(double divider, size_t dividend_line, size_t dividend_col) { matrix_[dividend_line][dividend_col] /= divider; }

    void SwapTwoLines(size_t lhs_line, size_t rhs_line) { matrix_[lhs_line].swap(matrix_[rhs_line]); }

    void SwapTwoElements(size_t lhs_line, size_t lhs_row, size_t rhs_line, size_t rhs_row) {
        double temp = matrix_[lhs_line][lhs_row];
        matrix_[lhs_line][lhs_row] = matrix_[rhs_line][rhs_row];
        matrix_[rhs_line][rhs_row] = temp;
    }

    void SetElement(size_t line, size_t row, double value) { matrix_[line][row] = value; }

private:
    std::vector<std::vector<double>> matrix_;
};

#endif //LABARATORNAYA1_MATRIX_H
