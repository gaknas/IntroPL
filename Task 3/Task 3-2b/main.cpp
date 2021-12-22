#include <iostream>

/**
 * \brief Пользовательский ввод необходимой точности вычисления.
 * \param message Мотивационное сообщение.
 * \return Точность вычисления.
 * \exception std::invalid_argument В случае, если размер последовательности меньше 1.
 */
double get_epsilon(const std::string& message);

/**
 * \brief Рассчитывает сумму последовательность с точностью (\a eps).
 * \param eps Точность вычисления.
 * \return Сумма последовательности.
 */
double get_sequence_summ(const double eps);

/**
 * \brief Рассчитывает значение рекуррентного члена в зависимости от индекса (\a index).
 * \param index Индекс, номер итерации.
 * \return Значение рекуррентного члена.
 */
double get_recurrent_member(const size_t index) noexcept;

/**
 * \brief Точка входа в программу.
 * \return 0 – в случае успеха,<br/>1 – в противном случае.
 */
int main() noexcept
{
    try
    {
        setlocale(LC_ALL, "Russian");
        const auto eps = get_epsilon("Введите точность вычислений ");
        const double summ = get_sequence_summ(eps);
        std::cout << "Сумма последовательности c точностью " << eps << " равна: " << summ << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

double get_sequence_summ(const double eps) {
    size_t i = 0;
    double summ = 0;
    double current = eps + 1;
    while (abs(current) >= eps) {
        if (i == 0) {
            current = 1;
        }
        else {
            current *= get_recurrent_member(i - 1);
        }
        summ += current;
        i++;
    }
    return summ;
}

double get_epsilon(const std::string& message)
{
    std::cout << message;
    double eps = 0;
    std::cin >> eps;
    if (eps < 0)
    {
        throw std::invalid_argument("Значение должно быть больше 0!");
    }

    return eps;
}

double get_recurrent_member(const size_t index) noexcept
{
    return -1.0 / (4 * pow(index, 2) + 6 * index + 2);
}