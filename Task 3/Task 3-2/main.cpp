#include <iostream>

/**
 * \brief Пользовательский ввод количества членов последовательности.
 * \param message Мотивационное сообщение.
 * \return Размер последовательности.
 * \exception std::invalid_argument В случае, если размер последовательности меньше 1.
 */
size_t get_sequence_size(const std::string& message);

/**
 * \brief Рассчитывает сумму последовательность с количеством членов (\a size).
 * \param size Количество членов последовательности.
 * \return Сумма последовательности.
 */
double get_sequence_summ(const size_t size);

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
        const auto size = get_sequence_size("Введите количество членов последовательности ");
        const double summ = get_sequence_summ(size);
        std::cout << "Сумма последовательности из " << size << " членов равна: " << summ << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

double get_sequence_summ(const size_t size) {
    double current = 0;
    double summ = 0;
    for (size_t i = 0; i < size; i++) {
        if (i == 0) {
            current = 1;
        }
        else {
            current *= get_recurrent_member(i - 1);
        }
        summ += current;
    }
    return summ;
}

size_t get_sequence_size(const std::string& message)
{
    std::cout << message;
    int size = 0;
    std::cin >> size;
    if (size < 1)
    {
        throw std::invalid_argument("Значение должно быть больше 0!");
    }

    return size;
}

double get_recurrent_member(const size_t index) noexcept
{
    return -1.0 / (4 * pow(index, 2) + 6 * index + 2);
}