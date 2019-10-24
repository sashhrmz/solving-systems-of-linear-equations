//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TEST_H
#define LABARATORNAYA1_TEST_H

#include "task_1.h"
#include "task_2.h"

class Test {
public:
    void TestFirstTask() {

        for(size_t i = 10; i < 4520; i += 400) {
            std::vector<std::vector<double>> matrix_vector;
            double temp;
            std::vector<std::vector<double>> result_vectors;
            result_vectors.resize(i);
            for(size_t j = 0; j < i; ++j) {
                matrix_vector.emplace_back();
                for(size_t k = 0; k < std::min((j + 2), i); ++k) {
                    temp = rand() + 1;
                    matrix_vector[j].push_back(temp);
                }
                result_vectors[j].resize(i);
                result_vectors[j][j] = 1;
            }

            double start_time = clock();

            Task_1(matrix_vector, result_vectors);

            double end_time = clock();
            double search_time = (end_time - start_time) / CLOCKS_PER_SEC;
            std::cout << i << " " << search_time << std::endl;
        }

        std::vector<std::vector<double>> result_vectors_1;
        result_vectors_1.resize(4);
        for(size_t j = 0; j < 4; ++j) {
            result_vectors_1[j].resize(4);
            result_vectors_1[j][j] = 1;
        }

        std::vector<std::vector<double>> first_test =
                {{-3, 1, 0, 0},
                {0, 2, 5, 0},
                {-3, -4, -5, -2},
                {3, -2, 1, -1}};
        double start_time = clock();

        std::vector<std::vector<double>> res = Task_1(first_test, result_vectors_1);

        double end_time = clock();
        double search_time = (end_time - start_time) / CLOCKS_PER_SEC;

        std::cout << "first_test" << std::endl;
        for(auto& vec : res) {
            for(auto& el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << search_time << std::endl;
        std::vector<std::vector<double>> result_vectors_2;
        result_vectors_2.resize(9);
        for(size_t j = 0; j < 9; ++j) {
            result_vectors_2[j].resize(9);
            result_vectors_2[j][j] = 1;
        }
        std::vector<std::vector<double>> second_test = {
                {-5, -5, 0, 0, 0, 0, 0, 0, 0},
                {3, 3, 0, 0, 0, 0, 0, 0, 0},
                {-5, 0, -4, 5, 0, 0, 0, 0, 0},
                {-4, 2, -5, 4, 0, 0, 0, 0, 0},
                {-3, -4, 1, 4, -4, 3, 0, 0, 0},
                {-5, -3, 4, 2, 4, -2, 2, 0, 0},
                {4, 0, -1, -1, 3, 1, 6, -5, 0},
                {0, 2, 2, -5, -2, 0, 1, 3, -4},
                {-5, 3, -5, 3, 1, 0, -3, 1, -4}};

        start_time = clock();

        res = Task_1(second_test, result_vectors_2);

        end_time = clock();
        search_time = (end_time - start_time) / CLOCKS_PER_SEC;


        std::cout << "second_test" << std::endl;
        for(auto& vec : res) {
            for(auto& el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << search_time << std::endl;
    }

    void TestSecondTask(bool test_flag) {
        std::vector<std::vector<double>> matrix = {{-3, 4, 2, -3, 2, 3, 4, 3},
                                                   {-3, 4, -1, 1, -4, -5, -1, 0},
                                                   {-6, 8, 1, -1, 1, 3, -3, -5},
                                                   {-12, 16, 2, -3, 4, -2, -3, 4},
                                                   {-24, 32, 4, -6, 3, -3, -1, -2},
                                                   {-48, 64, 8, -12, 6, -4, 3, -3},
                                                   {-96, 1280, 16, -24, 12, -8, -1, 4},
                                                   {2, -1, -3, -4, -5, 4, 1, -5}};

        std::vector<std::vector<double>> result_vector = {{79}, {-51}, {-29}, {33}, {2}, {59}, {149}, {-59}};
        matrix.size();
        std::vector<std::vector<double>> L_matrix;
        L_matrix.resize(matrix.size());
        for (int j = 0; j < matrix.size(); ++j) {
            L_matrix[j].resize(matrix.size());
        }

        std::vector<std::vector<double>> P_matrix;
        P_matrix.resize(matrix.size());
        for (int j = 0; j < matrix.size(); ++j) {
            P_matrix[j].resize(matrix.size());
            P_matrix[j][j] = 1;
        }
        Task_2(P_matrix, L_matrix, matrix, result_vector);
        OutputPLUV(P_matrix, L_matrix, matrix, result_vector);
        matrix = {{1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 2, 4, 8, 16, 32, 64, 128, 256},
                  {1, 3, 9, 27, 81, 243, 729, 2187, 6561},
                  {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536},
                  {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625},
                  {1, 6, 36, 216, 1296, 7776, 46656, 279936, 1679616},
                  {1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801},
                  {1, 8, 64, 512, 4096, 32768, 262144, 2097152, 16777216},
                  {1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721}};
        result_vector = {{9}, {511}, {9841}, {87381}, {488281}, {2015539}, {6725601}, {19173961}, {48427561}};
        matrix.size();
        L_matrix.clear();
        L_matrix.resize(matrix.size());
        for (int j = 0; j < matrix.size(); ++j) {
            L_matrix[j].resize(matrix.size());
        }

        P_matrix.clear();
        P_matrix.resize(matrix.size());
        for (int j = 0; j < matrix.size(); ++j) {
            P_matrix[j].resize(matrix.size());
            P_matrix[j][j] = 1;
        }
        Task_2(P_matrix, L_matrix, matrix, result_vector);
        OutputPLUV(P_matrix, L_matrix, matrix, result_vector);

        //test plu with random matrix and solutions
       if(test_flag) {
            for (size_t i = 4; i < 50; i += 4) {
                std::vector<std::vector<double>> matrix_vector;
                result_vector.clear();
                std::vector<double> one_value;
                double temp;
                for (size_t j = 0; j < i; ++j) {
                    matrix_vector.emplace_back();
                    for (size_t k = 0; k < i; ++k) {
                        temp = rand() + 1;
                        matrix_vector[j].push_back(temp);
                    }
                    temp = rand() + 1;
                    one_value.push_back(temp);
                    result_vector.push_back(one_value);
                    one_value.clear();
                }
                matrix_vector.size();
                L_matrix.clear();
                L_matrix.resize(matrix_vector.size());
                for (int j = 0; j < matrix_vector.size(); ++j) {
                    L_matrix[j].resize(matrix_vector.size());
                }

                P_matrix.clear();
                P_matrix.resize(matrix_vector.size());
                for (int j = 0; j < matrix_vector.size(); ++j) {
                    P_matrix[j].resize(matrix_vector.size());
                    P_matrix[j][j] = 1;
                }
                Task_2(P_matrix, L_matrix, matrix_vector, result_vector);
            }
        }
    }

private:
    void OutputPLUV(std::vector<std::vector<double>>& P_matrix, std::vector<std::vector<double>>& L_matrix,
                    std::vector<std::vector<double>>& U_matrix, std::vector<std::vector<double>>& values) {
        std::cout << "P matrix : " << std::endl;
        for(auto vec : P_matrix) {
            for(auto el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "L matrix : " << std::endl;
        for(auto vec : L_matrix) {
            for(auto el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "U matrix : " << std::endl;
        for(auto vec : U_matrix) {
            for(auto el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Solution : " << std::endl;
        for(auto vec : values) {
            for(auto el : vec) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //LABARATORNAYA1_TEST_H
