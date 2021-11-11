#include <cmath>
#include <iostream>

const double A = 2.5;

/**
 \brief Функция рассчитывает значение в точке
 /param value значение в точке
 /return Значение функции
 */
double getFunctionLessTreshold(const double value);

/**
 \brief Функция рассчитывает значение в точке
 /param value значение в точке
 /return Значение функции
 */
double getFunctionEqualTreshold(const double value);

/**
 \brief Функция рассчитывает значение в точке
 /param value значение в точке
 /return Значение функции
 */
double getFunctionAboveTreshold(const double value);

/**
 \brief Точка входа в программу
 /return 0 в случае успеха
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    const double THRESHOLD = 0.5;

    std::cout << "Введите значение x = ";
    double x;
    std::cin >> x;

    double y;
    if (x < THRESHOLD)
    {
        y = getFunctionLessTreshold(x);
    }
    else if (x > THRESHOLD)
    {
        y = getFunctionAboveTreshold(x);
    }
    else
    {
        y = getFunctionEqualTreshold(x);
    }

    std::cout << "y = " << y;

    return 0;
}

double getFunctionLessTreshold(const double value)
{
    return sqrt(A * pow(value, 2) + 1);
}

double getFunctionEqualTreshold(const double value)
{
    return A * value + 3;
}


double getFunctionAboveTreshold(const double value)
{
    return sqrt(pow(A, 2) * value - 1);
}
