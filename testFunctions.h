#ifndef PARTICLESWARMOPTIMIZATION_TESTFUNCTIONS_H
#define PARTICLESWARMOPTIMIZATION_TESTFUNCTIONS_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace TestFunctions {

    float randGen(const float &min, const float &max) {

        static thread_local mt19937 generator(123);
        uniform_real_distribution<float> distribution(min, max);
        return distribution(generator);
    }

    float sphereFun(float x, float y) {return pow(x, 2) + pow(y, 2);}

    float goldseinFun(float x, float y) {
        float p, p1;
        p = 1 + pow(x + y + 1, 2) * (19 - 14 * x + 3 * pow(x, 2) - 14 * y + 6 * x * y + 3 * pow(y, 2));
        p1 = 30 + pow(2 * x - 3 * y, 2) * (18 - 32 * x + 12 * pow(x, 2) + 48 * y - 36 * x * y + 27 * pow(y, 2));
        return p * p1;
    }

    float mcCormickFun(float x, float y) {return sin(x + y) + pow(x - y, 2) - 1.5 * x + 2.5 * y + 1;}

    float eggHolderFun(float x, float y) {
        float r1, r2;
        r1 = sin(sqrt(abs((x / 2) + y + 47)));
        r2 = sin(sqrt(abs(x - (y + 47))));
        return -(y + 47) * r1 - x * r2;
    }
};

#endif //PARTICLESWARMOPTIMIZATION_TESTFUNCTIONS_H
