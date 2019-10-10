// Copyright 2019 GrigoriyLafutkin <grigoriylafutkin@yandex.ru>

#include <iostream>
#include <cmath>


float MyFunc(const float &x)
{
    return (x * x * sin(x));
}
size_t Fib(const size_t &index)
{
    size_t m = 0;
    size_t f = 0;
    size_t f1 = 1;
    size_t f2 = 1;
    while (m < index - 1)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        ++m;
    }
    return f1;
}

void Print(const float & lym1, const float &lym2)
{
    std::cout << (lym1 + lym2) / 2 << std::endl;
}

void FibSearch(float &a, float &b)
{
    float eps = 0.1;
    size_t index = 0;
    std::cout << "Please enter index number Fib: ";
    std::cin >> index;
    float fb1 = Fib(index);
    float fb2 = Fib(index + 1);
    float lymbda_1 = a + (fb2 - fb1) / fb2 * (b - a); // В методичке без умножения на (b-a).
    float lymbda_2 = a + fb1 / fb2 * (b - a);
    for (size_t i = 0; i < index; ++i)
    {
        if (MyFunc(a) > MyFunc(b))
        {
            a = lymbda_1;
            lymbda_1 = lymbda_2;
            lymbda_2 = a + b - lymbda_1;
        }
        else {
            b = lymbda_2;
            lymbda_2 = lymbda_1;
            lymbda_1 = a + b - lymbda_2;
        }
        if ((lymbda_2 - lymbda_1) <= eps)
            break;
    }
    Print(lymbda_1, lymbda_2);
}
