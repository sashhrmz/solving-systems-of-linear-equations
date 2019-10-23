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

        for(size_t i = 10; i < 4520; i += 500) {
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
//
//        std::vector<std::vector<double>> first_test =
//                {{-3, 1, 0, 0},
//                {0, 2, 5, 0},
//                {-3, -4, -5, -2},
//                {3, -2, 1, -1}};
//        double start_time = clock();
//
//        std::vector<std::vector<double>> res = Task_1(first_test, );
//
//        double end_time = clock();
//        double search_time = (end_time - start_time) / CLOCKS_PER_SEC;
//
//        std::cout << "first_test" << std::endl;
//        for(auto& vec : res) {
//            for(auto& el : vec) {
//                std::cout << el << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << search_time << std::endl;
//        std::vector<std::vector<double>> second_test = {
//                {-5, -5, 0, 0, 0, 0, 0, 0, 0},
//                {3, 3, 0, 0, 0, 0, 0, 0, 0},
//                {-5, 0, -4, 5, 0, 0, 0, 0, 0},
//                {-4, 2, -5, 4, 0, 0, 0, 0, 0},
//                {-3, -4, 1, 4, -4, 3, 0, 0, 0},
//                {-5, -3, 4, 2, 4, -2, 2, 0, 0},
//                {4, 0, -1, -1, 3, 1, 6, -5, 0},
//                {0, 2, 2, -5, -2, 0, 1, 3, -4},
//                {-5, 3, -5, 3, 1, 0, -3, 1, -4}};
//
//        start_time = clock();
//
//        res = Task_1(second_test);
//
//        end_time = clock();
//        search_time = (end_time - start_time) / CLOCKS_PER_SEC;
//
//
//        std::cout << "second_test" << std::endl;
//        for(auto& vec : res) {
//            for(auto& el : vec) {
//                std::cout << el << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << search_time << std::endl;
    }

    void TestSecondTask() {
        std::vector<std::vector<double>> value = {{3}, {-3}, {-5}, {5}};

        std::vector<std::vector<double>> matrix = {{-3, 4, 2, -3, 2, 3, 4, 3},
                                                   {-3, 4, -1, 1, -4, -5, -1, 0},
                                                   {-6, 8, 1, -1, 1, 3, -3, -5},
                                                   {-12, 16, 2, -3, 4, -2, -3, 4},
                                                   {-24, 32, 4, -6, 3, -3, -1, -2},
                                                   {-48, 64, 8, -12, 6, -4, 3, -3},
                                                   {-96, 1280, 16, -24, 12, -8, -1, 4},
                                                   {2, -1, -3, -4, -5, 4, 1, -5}};
        for(size_t i = 4; i < 50; i += 4) {
            std::vector<std::vector<double>> matrix_vector;
            std::vector<std::vector<double>> result_vector;
            std::vector<double> one_value;
            double temp;
            for(size_t j = 0; j < i; ++j) {
                matrix_vector.emplace_back();
                for(size_t k = 0; k < i; ++k) {
                    temp = rand() + 1;
                    matrix_vector[j].push_back(temp);
                }
                temp = rand() + 1;
                one_value.push_back(temp);
                result_vector.push_back(one_value);
                one_value.clear();
            }
            double start_time = clock();

            Task_2(matrix_vector, result_vector);

            double end_time = clock();
            double search_time = (end_time - start_time) / CLOCKS_PER_SEC;
            std::cout << i << " - " << search_time << std::endl;
        }
    }
};

#endif //LABARATORNAYA1_TEST_H
