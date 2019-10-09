// Copyright 2019 GrigoriyLafutkin <grigoriylafutkin@yandex.ru>

#include <iostream>
#include <cmath>
#include <random>
#include <map>
#include <chrono>

static std::mt19937_64 gen{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()) };

float MyFunc(const float& x)
{
    return (x * x * sin(x));
}
float MyFuncSin5x(const float& x)
{
    return (x * x * sin(x) * sin(5 * x));
}

size_t Search_N(const float& p, const float& q)
{
    return (log(1 - p) / log(1 - q));
}
void Print(const float& p, const float& q, const float& xMin)
{
    std::cout << "p = " << p << " ";
    std::cout << "q = " << q << " | ";
    std::cout << "xMin = " << xMin << std::endl;
}
void RandSearch(const float& a, const float& b)
{
    std::uniform_real_distribution<float> distr(a, b);
    float xMin = distr(gen);
    for (float p = 0.90; p <= 0.99; p += 0.01)
    {
        for (float q = 0.005; q <= 0.1; q += 0.005)
        {
            for (size_t i = 0; i < Search_N(p, q); ++i)
            {
                //std::uniform_real_distribution<float> distr(a, b);
                float buf = distr(gen);
                if (MyFunc(buf) < MyFunc(xMin))
                {
                    xMin = buf;
                }
            }
            Print(p, q, xMin);
        }
    }
}

void RandSearchSin5x(const float& a, const float& b)
{
    std::uniform_real_distribution<float> distr(a, b);
    float xMin = distr(gen);
    for (float p = 0.90; p <= 0.99; p += 0.01)
    {
        for (float q = 0.005; q <= 0.1; q += 0.005)
        {
            for (size_t i = 0; i < Search_N(p, q); ++i)
            {
                //std::uniform_real_distribution<float> distr(a, b);
                float buf = distr(gen);
                if (MyFuncSin5x(buf) < MyFuncSin5x(xMin))
                {
                    xMin = buf;
                }
            }
            Print(p, q, xMin);
        }
    }
}
