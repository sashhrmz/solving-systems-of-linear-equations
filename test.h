//
// Created by sasha on 22/10/19.
//

#ifndef LABARATORNAYA1_TEST_H
#define LABARATORNAYA1_TEST_H

#include <map>
#include "task_1.h"
#include "task_2.h"

class Test {
public:
    std::map<size_t, double> TestFirstTask() {
        std::map<size_t, double> work_time;
        for(size_t i = 10; i < 2020; i += 500) {
            std::vector<std::vector<double>> matrix_vector;
            double temp;
            for(size_t j = 0; j < i; ++j) {
                matrix_vector.emplace_back();
                for(size_t k = 0; k < std::min((j + 2), i); ++k) {
                    temp = rand() + 1;
                    matrix_vector[j].push_back(temp);
                }
            }
            double start_time = clock(); // начальное время

            Task_1(matrix_vector);

            double end_time = clock(); // конечное время
            double search_time = (end_time - start_time) / CLOCKS_PER_SEC; // искомое время
            work_time.insert({i, search_time});
            std::cout << i << " - " << search_time << std::endl;
        }
    }

    void TestSecondTask() {
        std::vector<double> row1 =  {5, 2, -2, 1};
        std::vector<double> row2 =  {-5, 2, 2, -1};
        std::vector<double> row3 =  {-3, 2, -2, 3};
        std::vector<double> row4 =  {1, -1, 4, -1};
        std::vector<std::vector<double>> value = {{3}, {-3}, {-5}, {5}};
        std::vector<double> row5 =  {4, 1, 5, 3, 1};

        std::vector<std::vector<double>> matrix = {row1, row2, row3, row4};
        double start_time = clock(); // начальное время

        Task_2(matrix, value);

        double end_time = clock(); // конечное время
        double search_time = (end_time - start_time) / CLOCKS_PER_SEC; // искомое время
        std::cout << search_time;
    }
};

#endif //LABARATORNAYA1_TEST_H
