// Copyright 2019 GrigoriyLafutkin <grigoriylafutkin@yandex.ru>

#include <iostream>
#include <cmath>
#include <random>
#include <map>
#include <chrono>

static std::mt19937_64 gen
{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count())
};

float MyFunc(const float &x)
{
    return x * x * sin(x);
}

float MyFuncSin5x(const float &x)
{
    return x * x * sin(x) * sin(5 * x);
}

float FuncRandom(const float &a, const float &b)
{
    std::uniform_real_distribution<float> distr(a, b);
    return distr(gen);
}

float Probability(const float &dF, const float &T)
{
    return exp(-dF / T);
}

void SimulatedAnnealing(const float &a, const float &b)
{
    std::uniform_real_distribution<float> distr(a, b);
    float x1 = distr(gen);
    size_t N = 0;
    float dF = 0;
    for (float T = 10000; T >= 0.01; T *= 0.95)
    {
        for (size_t i = a; i < b; ++i)
        {
            float x = FuncRandom(a, b);
            dF = MyFunc(x) - MyFunc(x1);
            if (dF <= 0)
            {
                x1 = x;
            } else {
                if (FuncRandom(0, 1) <= Probability(dF, T))
                {
                    x1 = x;
                }
            }
        }
        ++N;
        std::cout << "N = " << N << " || " << "T = " << T << " || " << "X = " << x1 << " || " << "f(x)" << MyFunc(x1) << std::endl;
    }
}
void SimulatedAnnealing(const float &a, const float &b)
{
    std::uniform_real_distribution<float> distr(a, b);
    float x1 = distr(gen);
    size_t N = 0;
    float dF = 0;
    for (float T = 10000; T >= 0.01; T *= 0.95)
    {
        for (size_t i = a; i < b; ++i)
        {
            float x = FuncRandom(a, b);
            dF = MyFuncSin5x(x) - MyFuncSin5x(x1);
            if (dF <= 0)
            {
                x1 = x;
            } else {
                if (FuncRandom(0, 1) <= Probability(dF, T))
                {
                    x1 = x;
                }
            }
        }
        ++N;
        std::cout << "N = " << N << " || " << "T = " << T << " || " << "X = " << x1 << " || " << "f(x)" << MyFuncSin5x(x1) << std::endl;
    }
}
