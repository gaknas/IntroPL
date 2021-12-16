#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * \brief ������������ ��� �������� ������� �������.
 */
enum class InputType
{
    /**
     * \brief ���� �������.
     */
    MANUALLY,

    /**
     * \brief �������� � �������������� ���������� ��������� �����.
     */
     RANDOMLY
};

/**
 * \brief ����� ���������� �������
 * \param size ������ �������
 * \param input_type ������ �������� �������
 * \param LOWER_BOUND ������ ������� ��� ��������� �����
 * \param UPPER_BOUND ������� ������� ��� ��������� �����
 * \return ����������� ������
 */
int* get_array(const size_t size, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND);

/**
 * \brief ����� � ������ ��������� �������
 * \param size ������ �������
 * \return ������ � ����������
 */
string to_string(const int*, const size_t size);

/**
 * \brief ������� ������������ ������ ���������, �������� ������� �� ������ ������ 5
 * \param size ������ �������
 * \return ������������ ���������
 */
int get_even_composition(int*, const size_t size);

/**
 * \brief ������� ���������� �������� ��������� �� ������ ����������� �������� ����� (\a A)
 * \param size ������ �������
 * \param A ����� A
 * \return ���������� ���������
 */
int get_odd_quantity(int*, const size_t size, const int A);

/**
 * \brief �������� ��� �������� �������� ������� ������� 3 �� �� �����
 * \param size ������ �������
 * \return ���������� ���������
 */
void multiply_elements(int*, const size_t size);

/**
 * \brief ���������� ��������������� ����� �� ��������� (min, max)
 * \param min ����������� �����
 * \param max ������������ �����
 * \return ��������� �����
 */
int Random(int min, int max);

/**
 * \brief ����� ����� � ���������
 * \return 0 � ������ ������
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    auto error_code = 0;
    int* my_array = nullptr;
    const int LOWER_BOUND = -11;
    const int UPPER_BOUND = 21;
    try
    {
        cout << "������� ������ ������� = ";
        size_t size;
        cin >> size;
        cout << "�������� ������ �������� �������: " << static_cast<int>(InputType::MANUALLY) << " - �������, " << static_cast<int>(InputType::RANDOMLY) << " - ��������� ���������� ������� ";
        int input_type;
        cin >> input_type;
        my_array = get_array(size, input_type, LOWER_BOUND, UPPER_BOUND);
        cout << "���������� ������:\n";
        cout << to_string(my_array, size);
        cout << "\n������������ ������ ���������, �������� ������� �� ������ ������ 5 = " << get_even_composition(my_array, size) << '\n';
        cout << "������� ����� A = ";
        int A;
        cin >> A;
        cout << "���������� �������� ��������� �� ������ ����������� �������� ����� (A) = " << get_odd_quantity(my_array, size, A) << '\n';
        cout << "������ ����� ���������� ���� �������� ��������� ������� ������� 3 �� �� �����:\n";
        multiply_elements(my_array, size);
        cout << to_string(my_array, size);
    }
    catch (exception& e)
    {
        cout << e.what();
        error_code = 1;
    }

    if (my_array != nullptr)
    {
        delete[] my_array;
        my_array = nullptr;
    }
    return error_code;
}

int* get_array(const size_t size, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND)
{
    if (size == 0)
        throw out_of_range("������������ ������ �������");

    const auto array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        switch (input_type)
        {
        case static_cast<int>(InputType::MANUALLY):
        {
            cout << "������� " << index + 1 << " ������� ������� = ";
            cin >> array[index];
            break;
        }
        case static_cast<int>(InputType::RANDOMLY):
        {
            array[index] = Random(LOWER_BOUND, UPPER_BOUND);
            break;
        }
        default:
            cout << "������!";
        }
    }

    return array;
}

string to_string(const int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("������ �� ����������");

    stringstream buffer;
    buffer << "{";
    for (size_t index = 0; index < size - 1; index++)
    {
        buffer << array[index] << ", ";
    }
    buffer << array[size - 1] << "}";
    return buffer.str();
}

int get_even_composition(int* array, const size_t size) {
    int comp = 1;
    for (size_t i = 0; i < size; i++) {
        if ((abs(array[i]) < 5) && (array[i] % 2 == 0))
            comp *= array[i];
    }
    if (comp == 1)
        comp = 0;
    return comp;
}

int get_odd_quantity(int* array, const size_t size, const int A) {
    int quan = 0;
    for (size_t i = 0; i < size; i++) {
        if ((abs(array[i]) > A) && (array[i] % 2 != 0))
            quan++;
    }
    return quan;
}

void multiply_elements(int* array, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] % 3 == 0)
            array[i] *= i;
    }
}

int Random(int min, int max) {
    return min + rand() % (max - min);
}