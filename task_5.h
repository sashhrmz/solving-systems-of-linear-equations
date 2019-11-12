//
// Created by sasha on 12/11/19.
//

#ifndef LABARATORNAYA1_TASK_5_H
#define LABARATORNAYA1_TASK_5_H
#include "matrix.h"

int Task_5(double n, std::vector<double> x, double w) {
    double k;
    bool flag = true;
    double norma;
    int t = 0;

    while(flag) {
        k = x[0];
        x[0] = (1 - w) * k + (w / n) * (1 - (n - 2) * x[1] - x[2]);
        k = x[1];
        x[1] = (1 - w) * k + (w / n) * (1 - x[0] - x[2]);
        k = x[2];
        x[2] = (1 - w) * k + (w / n) * (1 - (n - 2) * x[1] - x[0]);
        norma = std::sqrt((n * x[0] + (n - 2) * x[1] + x[2] - 1) *
                          (n * x[0] + (n - 2) * x[1] + x[2] - 1) +
                          (n - 2) * (x[0] + n * x[1] + x[2] - 1) * (x[0] + n * x[1] + x[2] - 1) +
                          (x[0] + (n - 2) * x[1] + n * x[2] - 1) *
                          (x[0] + (n - 2) * x[1] + n * x[2] - 1));
        if(norma < 0.0000000001) { flag = false; }
        ++t;
    }
    return t;
}
#endif //LABARATORNAYA1_TASK_5_H
