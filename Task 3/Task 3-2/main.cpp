#include <iostream>

/**
 * \brief ���������������� ���� ���������� ������ ������������������.
 * \param message ������������� ���������.
 * \return ������ ������������������.
 * \exception std::invalid_argument � ������, ���� ������ ������������������ ������ 1.
 */
size_t get_sequence_size(const std::string& message);

/**
 * \brief ������������ �������� ������������� ����� � ����������� �� ������� (\a index).
 * \param index ������, ����� ��������.
 * \return �������� ������������� �����.
 */
double get_recurrent_member(const size_t index) noexcept;

/**
 * \brief ����� ����� � ���������.
 * \return 0 � � ������ ������,<br/>1 � � ��������� ������.
 */
int main() noexcept
{
    try
    {
        setlocale(LC_ALL, "Russian");
        const auto size = get_sequence_size("������� ���������� ������ ������������������ ");
        double current = 0;
        double summ = 0;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                current = 1;
            }
            else {
                current *= get_recurrent_member(i - 1);
            }
            summ += current;
        }
        std::cout << "����� ������������������ �� " << size << " ������ �����: " << summ << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

size_t get_sequence_size(const std::string& message)
{
    std::cout << message;
    int size = 0;
    std::cin >> size;
    if (size < 1)
    {
        throw std::invalid_argument("�������� ������ ���� ������ 0!");
    }

    return size;
}

double get_recurrent_member(const size_t index) noexcept
{
    return -1.0 / (4 * pow(index, 2) + 6 * index + 2);
}