#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iomanip>
#include <iostream>

//using namespace std;

/**
 * \brief Это функция выполняет вычисление по заданной формуле
 * \param x параметр х
 * \param y параметр y
 * \param z параметр z
 * \return значение функции
 */
double getA(const double x, const double y, const double z);
/**
 * \brief Это функция выполняет вычисление по заданной формуле
 * \param x параметр х
 * \param y параметр y
 * \param z параметр z
 * \return значение функции
 */
double getB(const double x, const double y, const double z);

/**
 * \brief Точка входа в программу
 * \return 0  в случае успеха
 */
int main()
{
    const double x = 0.61;
    const double y = 0.9;
    const double z = 0.3;

    const double a = getA(x, y, z);
    const double b = getB(x, y, z);


    std::cout << std::setprecision(9) << "x = " << x << " y = " << y << " z = " << z
        << " a = " << a << " b = " << b << std::endl;
    return 0;
}



double getA(const double x, const double y, const double z)
{
    return (pow(z, 2 * x) + pow(y, -x) * cos(z + y) * x) / (x + 1);
}

double getB(const double x, const double y, const double z)
{
    return sqrt(pow(x, 2) + y) - pow(y, 2) * pow(sin((x + z) / x), 3);
}