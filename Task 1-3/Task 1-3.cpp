#include <iostream>

/**
\brief Рассчитывает расстояние между телами массы mass сила взаимодействия между которыми равна force
\param mass масса тел
\param force сила взаимодействия
\param G гравитационная постоянная
\return расстояние между телами
*/
double getDistance(double mass, double force, double G = 6.67 * pow(10, -11));

/**
\brief Точка входа в программу
\return В случае успеха возвращаем 0
*/
int main()
{
    std::cout << "Insert body mass value = ";
    double mass;
    std::cin >> mass;

    std::cout << "Insert force value = ";
    double force;
    std::cin >> force;
    force *= pow(10, -5);

    const double distance = getDistance(mass, force);
    std::cout << "Distance between bodies = " << distance;
    return 0;
}

double getDistance(const double mass, const double force, const double G)
{
    return mass * sqrt(G / force);
}