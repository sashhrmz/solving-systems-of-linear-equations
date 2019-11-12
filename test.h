//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TEST_H
#define LABARATORNAYA1_TEST_H

#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"

class Test {
public:
    void TestFirstTask(bool time_test, bool first_test_, bool second_test_) {
        std::ofstream fout("output_first.txt");
        //Random tests, begin.
        if (time_test) {
            for (size_t i = 10; i < 5520; i += 400) {
                std::vector<std::vector<double>> matrix_vector;
                double temp;
                std::vector<std::vector<double>> result_vectors;
                result_vectors.resize(i);
                for (size_t j = 0; j < i; ++j) {
                    matrix_vector.emplace_back();
                    for (size_t k = 0; k < std::min((j + 2), i); ++k) {
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
                fout << i << " " << search_time << std::endl;
            }
        }
        //Random tests, end.

        //First test, begin.
        if(first_test_) {
            std::vector<std::vector<double>> result_vectors_1;
            result_vectors_1.resize(4);
            for (size_t j = 0; j < 4; ++j) {
                result_vectors_1[j].resize(4);
                result_vectors_1[j][j] = 1;
            }

            std::vector<std::vector<double>> first_test;
            ReadSquareMatrix(first_test, "input_1_1.txt");
            double start_time = clock();

            Task_1(first_test, result_vectors_1);

            double end_time = clock();
            double search_time = (end_time - start_time) / CLOCKS_PER_SEC;

            fout << "first_test" << std::endl;
            for (auto &vec : result_vectors_1) {
                for (auto &el : vec) {
                    fout << el << " ";
                }
                fout << std::endl;
            }
            fout << search_time << std::endl;
        }
        //First test, end.

        //Second test, begin.
        if(second_test_) {
            std::vector<std::vector<double>> result_vectors_2;
            result_vectors_2.resize(9);
            for (size_t j = 0; j < 9; ++j) {
                result_vectors_2[j].resize(9);
                result_vectors_2[j][j] = 1;
            }
            std::vector<std::vector<double>> second_test;
            ReadSquareMatrix(second_test, "input_1_2.txt");
            double start_time = clock();

            Task_1(second_test, result_vectors_2);

            double end_time = clock();
            double search_time = (end_time - start_time) / CLOCKS_PER_SEC;


            fout << "second_test" << std::endl;
            for (auto &vec : result_vectors_2) {
                for (auto &el : vec) {
                    fout << el << " ";
                }
                fout << std::endl;
            }
            fout << search_time << std::endl;
        }
        //Second test, end.
        fout << "the end of test";
    }

    void TestSecondTask(bool first_test_, bool second_test_, bool test_flag) {
        std::ofstream fout("output_second.txt");
        std::vector<std::vector<double>> matrix;
        std::vector<std::vector<double>> result_vector;
        std::vector<std::vector<double>> L_matrix;
        std::vector<std::vector<double>> P_matrix;

        if(first_test_) {
            ReadSquareMatrix(matrix, "input_2_1_matrix.txt");
            ReadLineMatrix(result_vector, "input_2_1_results.txt");
            L_matrix.resize(matrix.size());
            for (int j = 0; j < matrix.size(); ++j) {
                L_matrix[j].resize(matrix.size());
            }

            P_matrix.resize(matrix.size());
            for (int j = 0; j < matrix.size(); ++j) {
                P_matrix[j].resize(matrix.size());
                P_matrix[j][j] = 1;
            }
            Task_2(P_matrix, L_matrix, matrix, result_vector);
            fout << "first test" << std::endl;
            for (auto el : result_vector) {
                fout << el[0] << " ";
            }
            fout << std::endl;
        }

        matrix.clear();
        result_vector.clear();

        if(second_test_) {
            ReadSquareMatrix(matrix, "input_2_2_matrix.txt");
            ReadLineMatrix(result_vector, "input_2_2_results.txt");
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
            fout << "second test" << std::endl;
            for (auto el : result_vector) {
                fout << el[0] << " ";
            }
            fout << std::endl;
        }

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
       fout << "the end of test";
    }

    void TestThirdTask(bool test_flag) {
        std::ofstream fout("output_third.txt");
        if(test_flag) {
            std::vector<size_t> D_matrix = {};

            for (size_t i = 100; i < 2001; i += 100) {
                std::vector<std::vector<double>> LLT_matrix;
                std::vector<std::vector<double>> U_matrix;
                double temp;
                std::vector<std::vector<double>> values1;
                std::vector<std::vector<double>> values2;
                std::vector<std::vector<double>> L1_matrix;
                std::vector<std::vector<double>> L2_matrix;
                values1.resize(i);
                L1_matrix.resize(i);
                L2_matrix.resize(i);
                U_matrix.resize(i);
                for (size_t k = 0; k < i; ++k) {
                    U_matrix[k].resize(i);
                }
                for (size_t j = 0; j < i; ++j) {
                    for (size_t k = j; k < i; ++k) {
                        temp = rand() + 1;
                        U_matrix[k][j] = temp;
                        U_matrix[j][k] = temp;
                    }
                    L1_matrix[j].resize(i);
                    L2_matrix[j].resize(i);
                    values1[j].push_back(rand() + 1);
                }
                LLT_matrix = U_matrix;
                values2 = values1;


                double start_time = clock();
                Task_3_LDLT(LLT_matrix, L1_matrix, D_matrix, values1);
                double end_time = clock();
                double search_time = (end_time - start_time) / CLOCKS_PER_SEC;
                fout << "LDLT " << i << " " << search_time << " ";
                start_time = clock();
                Task_3_LU(L2_matrix, U_matrix, values2);
                end_time = clock();
                search_time = (end_time - start_time) / CLOCKS_PER_SEC;
                fout << "LU " << i << " " << search_time << std::endl;
            }
        }
        fout << "the end of test";
    }

    void TestForthTask(bool test_flag) {
        std::ofstream fout("output_fourth.txt");
        if(test_flag) {
            std::vector<std::vector<double>> matrix;
            std::vector<double> values;
            ReadMatrixWithValues(matrix, values, "input_4_1.txt");
            Task_4(matrix, values);
            for (auto el : values) {
                fout << el << " ";
            }
            fout << std::endl;
            matrix.clear();
            values.clear();
            ReadMatrixWithValues(matrix, values, "input_4_2.txt");
            Task_4(matrix, values);
            for (auto el : values) {
                fout << el << " ";
            }
        }
        fout << "the end of test";
    }

    void TestFivesTask() {
        std::ofstream fout("output_fives.txt");
        for(int i = 500; i < 4010; i += 500) {
            std::vector<double> x = {1, 1, 1};
            int t = Task_5(i, x, 0.6);
            fout << i << " - " << t << " iterations" << std::endl;
        }
    }
};

#endif //LABARATORNAYA1_TEST_H
