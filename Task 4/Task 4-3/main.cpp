#include <iostream>
#include <sstream>
#include <random>
#include <iomanip>

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
 * \param cols ���������� ����� � �������
 * \param rows ���������� �������� � �������
 * \param input_type ������ �������� �������
 * \param LOWER_BOUND ������ ������� ��� ��������� �����
 * \param UPPER_BOUND ������� ������� ��� ��������� �����
 * \return ����������� ������
 */
int** get_matrix(const size_t cols, const size_t rows, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND);

/**
 * \brief ������� ��� ��������� ������� �������
 * \param message ������������� ��������� ��� ������������
 * \return ������ �������
 */
size_t get_size(const std::string& message);

/**
 * \brief ����� � ������ ��������� �������
 * \param cols ���������� ����� � �������
 * \param rows ���������� �������� � �������
 * \return ������ � ����������
 */
string to_string(int**, const size_t cols, const size_t rows);

/**
 * \brief �������� �������� ������� 3 �� 0
 * \param cols ���������� ����� � �������
 * \param rows ���������� �������� � �������
 */
void replace_multiple_three(int**, const size_t cols, const size_t rows);

/**
 * \brief ������� ������ � ������� ������ ������� ������ ��������������
 * \param cols ���������� ����� � �������
 * \param rows ���������� �������� � �������
 */
void delete_cols(int**&, size_t& cols, size_t rows);

/**
 * \brief ������� ������ ��� ������� (\a index)
 * \param cols ���������� ����� � �������
 * \param rows ���������� �������� � �������
 * \param index ����� ������ ������� ���� �������
 */
void delete_col(int**&, size_t& cols, size_t rows, const size_t index);


/**
 * \brief ����� ����� � ���������
 * \return 0 � ������ ������
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int** my_matrix = nullptr;
    const int LOWER_BOUND = -10;
    const int UPPER_BOUND = 20;
    size_t cols = 0;
    size_t rows = 0;
    try
    {
        cols = get_size("������� ���������� ����� ������� = ");
        rows = get_size("������� ���������� �������� ������� = ");
        cout << "�������� ������ �������� �������: " << static_cast<int>(InputType::MANUALLY) << " - �������, " << static_cast<int>(InputType::RANDOMLY) << " - ��������� ���������� ������� ";
        int input_type;
        cin >> input_type;
        my_matrix = get_matrix(cols, rows, input_type, LOWER_BOUND, UPPER_BOUND);
        cout << "���������� ������:\n";
        cout << to_string(my_matrix, cols, rows);
        replace_multiple_three(my_matrix, cols, rows);
        cout << "������ ����� ������ ���� ��������� ������� 3 �� 0:\n";
        cout << to_string(my_matrix, cols, rows);
        delete_cols(my_matrix, cols, rows);
        cout << "������ ����� �������� ���� ����� � ������� ������ ������� ������ ��������������:\n";
        cout << to_string(my_matrix, cols, rows);
    }
    catch (exception& e)
    {
        cout << e.what();
        error_code = 1;
    }

    if (my_matrix != nullptr)
    {
        for (size_t col = 0; col < cols; col++) {
            delete[] my_matrix[col];
        }
        my_matrix = nullptr;
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

int** get_matrix(const size_t cols, const size_t rows, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND)
{
    if (cols == 0 || rows == 0)
        throw out_of_range("������������ ������ �������");

    int** matrix = new int*[cols];
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());
    const std::uniform_int_distribution<> uniformIntDistribution(LOWER_BOUND, UPPER_BOUND);
    for (size_t col = 0; col < cols; col++)
    {
        matrix[col] = new int[rows];
        for (size_t row = 0; row < rows; row++) {
            switch (input_type)
            {
            case static_cast<int>(InputType::MANUALLY):
            {
                cout << "������� matrix[" << col << "][" << row <<"] = ";
                cin >> matrix[col][row];
                break;
            }
            case static_cast<int>(InputType::RANDOMLY):
            {
                matrix[col][row] = uniformIntDistribution(gen);
                break;
            }
            default:
                cout << "������!";
            }
        }
    }

    return matrix;
}

string to_string(int** matrix, const size_t cols, const size_t rows)
{
    if (matrix == nullptr)
        throw invalid_argument("������ �� ����������");

    stringstream buffer;
    for (size_t col = 0; col < cols; col++) {
        if (col == 0)
            buffer << "{{";
        else
            buffer << " {";
        for (size_t row = 0; row < rows - 1; row++) {
            buffer << std::setw(4) << std::right << matrix[col][row] << ",";
        }
        if (col == cols - 1) 
            buffer << std::setw(4) << std::right << matrix[col][rows - 1] << "}}\n";
        else 
            buffer << std::setw(4) << std::right << matrix[col][rows - 1] << "}\n";
    }
    return buffer.str();
}

void replace_multiple_three(int** matrix, const size_t cols, const size_t rows) {
    for (size_t col = 0; col < cols; col++) {
        for (size_t row = 0; row < rows; row++) {
            if (matrix[col][row] % 3 == 0)
                matrix[col][row] = 0;
        }
    }
}

void delete_cols(int**& matrix, size_t& cols, size_t rows) {
    for (size_t col = 0; col < cols - 1; col++) {
        if (matrix[col][1] > matrix[col][rows - 2])
            delete_col(matrix, cols, rows, col);
    }
}

void delete_col(int **&matrix, size_t& cols, size_t rows, const size_t index) {
    int** newMatrix = new int*[cols - 1];
    if (index == 0) {
        for (size_t col = 1; col < cols; col++) {
            newMatrix[col - 1] = new int[rows];
            for (size_t row = 0; row < rows; row++) {
                newMatrix[col - 1][row] = matrix[col][row];
            }
        }
    }
    else if (index == cols - 1) {
        for (size_t col = 0; col < (cols - 1); col++) {
            newMatrix[col] = new int[rows];
            for (size_t row = 0; row < rows; row++) {
                newMatrix[col][row] = matrix[col][row];
            }
        }
    }
    else {
        for (size_t col = 0; col < index; col++) {
            newMatrix[col] = new int[rows];
            for (size_t row = 0; row < rows; row++) {
                newMatrix[col][row] = matrix[col][row];
            }
        }
        for (size_t col = index + 1; col < cols; col++) {
            newMatrix[col - 1] = new int[rows];
            for (size_t row = 0; row < rows; row++) {
                newMatrix[col - 1][row] = matrix[col][row];
            }
        }
    }
    for (size_t col = 0; col < cols; col++) {
        delete[] matrix[col];
    }
    matrix = newMatrix;
    cols = cols - 1;
}