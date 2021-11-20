#include <iostream>

const double SM_IN_INCH = 2.54;

/**
 * \brief переводит сантиметры в дюймы
 * \param cm_length длина в сантиметрах
 * \return длину в дюймах
 */
double convertToInches(double cm_length);


/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
 */
int main()
{
    std::cout << "Input length in centimeters = ";
    double cm_length;
    std::cin >> cm_length;

    const double inch_length = convertToInches(cm_length);

    std::cout << "Length in inches = " << inch_length << "\n";
    return 0;
}

double convertToInches(const double cm_length)
{
    return cm_length / SM_IN_INCH;
}