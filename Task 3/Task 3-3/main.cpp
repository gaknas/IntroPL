#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * \brief Рассчитывает значение функции в заданной точке (\a x).
 * \param x Абсцисса заданной точки.
 * \return Значение фунции.
 */
double get_function_value(const double x);

/**
 * \brief Рассчитывает сумму функционального ряда в заданной точке (\a x) с точностью (\a eps).
 * \param x Абсцисса заданной точки.
 * \param eps Точность вычисления.
 * \return Сумма ряда.
 */
double get_row_summ(const double x, const double eps);

/**
 * \brief Рассчитывает значение рекуррентного члена в зависимости от индекса (\a index) в заданной точке (\a x).
 * \param index Индекс, номер итерации.
 * \param x Абсцисса заданной точки.
 * \return Значение рекуррентного члена.
 */
double get_recurrent_member(const size_t index, const double x);

/**
 * \brief Пользовательский ввод значения.
 * \param message Мотивационное сообщение.
 * \return необходимое значение.
 * \exception std::invalid_argument В случае, если введенное значения несоответствует условиям.
 */
double get_value(const std::string& message);

/**
 * \brief Точка входа в программу.
 * \return 0 – в случае успеха,<br/>1 – в противном случае.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    const double START = 0.1;
    double x = START;
    const double END = 1;
    const double STEP = get_value("введите шаг h ");;
    const double EPS = get_value("введите точность для вычисления функционального ряда e ");
    while (x <= END + (std::numeric_limits<double>::epsilon()))
    {
        const double Y = get_function_value(x);
        const double S = get_row_summ(x, EPS);
        std::cout << "x = " << std::setprecision(10) << x << " y = " << Y << " S = " << S << '\n';
        x += STEP;
    }
    return 0;
}

double get_value(const std::string& message)
{
    std::cout << message;
    double value = 0;
    std::cin >> value;
    if (value <= 0)
    {
        throw std::invalid_argument("Значение должно быть больше 0!");
    }
    return value;
}

double get_function_value(const double x)
{
    return 2 * (pow(cos(x), 2) - 1);
}

double get_row_summ(const double x, const double eps)
{
    int i = 1;
    double summ = 0;
    double current = eps + 1;
    while (abs(current) >= eps) {
        if (i == 1) {
            current = -pow(2*x, 2) / 2;
        }
        else {
            current *= get_recurrent_member(i - 1, x);
        }
        summ += current;
        i++;
    }
    return summ;
}

double get_recurrent_member(const size_t index, const double x)
{
    return -1.0 * pow(2*x, 2) / (4 * pow(index, 2) + 6 * index + 2);
}