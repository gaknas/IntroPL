#include <iostream>
#include <sstream>
#include <random>

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
 * \brief ������� ��� ��������� ������� �������
 * \param message ������������� ��������� ��� ������������
 * \return ������ �������
 */
size_t get_size(const std::string& message);

/**
 * \brief ����� � ������ ��������� �������
 * \param size ������ �������
 * \return ������ � ����������
 */
string to_string(const int*, const size_t size);

/**
 * \brief �������� ��������� ������������� ������� ������� �� ������ �������
 * \param size ������ �������
 */
void replace_last_negative(int*, const size_t size);

/**
 * \brief ������� �� ������� ��� ����� � ������� ������ � ��������� ����� ����������
 * \param size ������ �������
 */
void delete_palindromes(int*&, size_t &size);

/**
 * \brief ������� �� ������� ������� ��� ������� (\a index)
 * \param size ������ �������
 * \param index ����� �������� ������� ���� �������
 */
void delete_element(int*&, size_t &size, const size_t index);

/**
 * \brief ������� �� ��������� ������� ����� ������ P �� ������������� �������
 * \param size ������ �������
 * \return ������ P
 */
int* �reate_m(int*, const size_t size);


/**
 * \brief ����� ����� � ���������
 * \return 0 � ������ ������
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int LOWER_BOUND = -10;
    const int UPPER_BOUND = 20;
    try
    {
        auto size = get_size("������� ������ ������� = ");
        cout << "�������� ������ �������� �������: " << static_cast<int>(InputType::MANUALLY) << " - �������, " << static_cast<int>(InputType::RANDOMLY) << " - ��������� ���������� ������� ";
        int input_type;
        cin >> input_type;
        my_array = get_array(size, input_type, LOWER_BOUND, UPPER_BOUND);
        cout << "���������� ������:\n";
        cout << to_string(my_array, size);
        replace_last_negative(my_array, size);
        delete_palindromes(my_array, size);
        cout << "\n������ ����� �������� ���� ��������� � ���������� ��������� � �������� ������:\n";
        cout << to_string(my_array, size);
        cout << "\n������ M:\n";
        cout << to_string(�reate_m(my_array, size), size);
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

size_t get_size(const std::string& message)
{
    int size = -1;
    std::cout << message;
    std::cin >> size;

    if (size < 0)
    {
        throw std::out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return size;
}

int* get_array(const size_t size, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND)
{
    if (size == 0)
        throw out_of_range("������������ ������ �������");

    const auto array = new int[size];
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());
    const std::uniform_int_distribution<> uniformIntDistribution(LOWER_BOUND, UPPER_BOUND);
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
            array[index] = uniformIntDistribution(gen);
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

void replace_last_negative(int* array, const size_t size) {
    size_t index = -1;
    for (size_t i = 0; i < size; i++) {
        if (array[i] < 0) {
            index = i;
        }
    }
    if (index == -1) {
        cout << "\n� ������� ��� ������������� �����";
    }
    else {
        array[index] = abs(array[0]);
        cout << "\n������ ����� ������ ���������� �������������� �������� �� ������ �������:\n";
        cout << to_string(array, size);
    }
}

void delete_palindromes(int *&array, size_t &size) {
    for (size_t i = 0; i < size - 1; i++) {
        int temp = abs(array[i]);
        if (temp % 10 == temp / 10) {
            delete_element(array, size, i);
        }
    }
}

void delete_element(int *&array, size_t &size, const size_t index) {
    int* newArray = new int[size - 1];
    if (index == 0) {
        for (size_t i = 1; i < size; i++) {
            newArray[i - 1] = array[i];
        }
    }
    else if (index == size - 1) {
        for (size_t i = 0; i < (size - 1); i++) {
            newArray[i] = array[i];
        }
    }
    else {
        for (size_t i = 0; i < index; i++) {
            newArray[i] = array[i];
        }
        for (size_t i = index + 1; i < size; i++) {
            newArray[i - 1] = array[i];
        }
    }
    delete[] array;
    array = newArray;
    size = size - 1;
}

int* �reate_m(int* P, const size_t size) {
    int* M = new int[size];
    for (size_t i = 0; i < size; i++) {
        if (P[i] % 2 == 0) {
            M[i] = P[i] * i;
        }
        else {
            M[i] = -P[i];
        }
    }
    return M;
}
