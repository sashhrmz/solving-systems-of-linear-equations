#include "test.h"

int main() {
    Test test;

    test.TestFirstTask(false, false, false);
    test.TestSecondTask(false, false, false);
    test.TestThirdTask(false);
    test.TestForthTask(false);
    test.TestFivesTask();

    return 0;
}