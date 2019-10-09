// Copyright 2019 GrigoriyLafutkin <grigoriylafutkin@yandex.ru>

#include <iostream>
#include <cmath>

float MyFunc(const float& x)
{
    return x * x * sin(x);
}

void PrintOPS(const float& N, const float& buf, const float& tmp)
{
    std::cout << "  | " << N << "  |  ";
    std::cout << buf << " " << "+-" << " " << tmp << std::endl;
}

void OptimalPassiveSearch(const float& a, const float& b)
{
    float eps = 0.1;
    float xMin = a;
    float N = 1;
    float dN = 1;
    while(dN > eps)
    {
        dN = ((b - a) / (N + 1));
        for (float i = a; i < b; i += dN)
        {
            if (MyFunc(i) < MyFunc(xMin))
            {
                xMin = i;
            }
        }
        PrintOPS(N, xMin, dN);
        ++N;
    }
}
