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
        const auto size = get_sequence_size("������� ���������� ������ ������������������ ");

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
    if (size < 0)
    {
        throw std::invalid_argument("�������� ������ ���� ������ ���� ����� 0!");
    }

    return size;
}

double get_recurrent_member(const size_t index) noexcept
{
    return 42;
}