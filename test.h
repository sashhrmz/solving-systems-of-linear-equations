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
        std::vector<double> row1 =  {9, 3};
        std::vector<double> row2 =  {4, 9, 3};
        std::vector<double> row3 =  {4, 5, 5, 3};
        std::vector<double> row4 =  {3, 5, 2, 3, 2};
        std::vector<double> row4_ =  {3, 5, 2, 1};
        std::vector<double> row5 =  {4, 1, 5, 3, 1, 1};
        std::vector<double> row6 =  {6, 2, 3, 3, 9, 9, 4};
        std::vector<double> row7 =  {2, 5, 3, 3, 1, 7, 3, 8};
        std::vector<double> row8 =  {1, 2, 2, 3, 1, 8, 2, 7, 1};
        std::vector<double> row9 =  {4, 2, 8, 7, 1, 1, 1, 3, 2, 1};
        std::vector<double> row10 = {2, 1, 8, 4, 1, 4, 1, 5, 3, 9, 5};
        std::vector<double> row11 = {4, 2, 8, 3, 2, 3, 3, 5, 2, 5, 3, 8};
        std::vector<double> row12 = {6, 8, 8, 3, 4, 5, 6, 7, 5, 1, 2, 3};

        std::vector<std::vector<double>> matrix = {row1, row2, row3, row4, row5, row6, row7, row8, row9, row10, row11, row12};

        std::vector<std::vector<double>> matrix1 = {row1, row2, row3, row4_};

        double start_time = clock(); // начальное время

        Task_1(matrix);

        double end_time = clock(); // конечное время
        double search_time = (end_time - start_time) / CLOCKS_PER_SEC; // искомое время
        std::cout << search_time;
    }

    void TestSecondTask() {
        std::vector<double> row1 =  {5, 2, -2, 1};
        std::vector<double> row2 =  {-5, 2, 2, -1};
        std::vector<double> row3 =  {-3, 2, -2, 3};
        std::vector<double> row4 =  {1, -1, 4, -1};
        std::vector<double> value = {3, -3, -5, 5};
        std::vector<double> row5 =  {4, 1, 5, 3, 1};

        std::vector<std::vector<double>> matrix = {row1, row2, row3, row4};
        Task_2(matrix, value);

    }
};

#endif //LABARATORNAYA1_TEST_H
