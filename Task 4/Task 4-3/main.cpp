#include <iostream>
#include <sstream>
#include <random>
#include <iomanip>

using namespace std;

/**
 * \brief Перечислимый тип способов задания массива.
 */
enum class InputType
{
    /**
     * \brief ввод вручную.
     */
    MANUALLY,

    /**
     * \brief создание с использованием генератора случайных чисел.
     */
     RANDOMLY
};

/**
 * \brief Метод заполнения массива
 * \param cols Количество строк в массиве
 * \param rows Количество столбцов в массиве
 * \param input_type Способ создания массива
 * \param LOWER_BOUND Нижняя граница для случайных чисел
 * \param UPPER_BOUND Верхняя граница для случайных чисел
 * \return Заполненный массив
 */
int** get_matrix(const size_t cols, const size_t rows, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND);

/**
 * \brief Функция для получения размера массива
 * \param message Мотивоционное сообщение для пользователя
 * \return Размер массива
 */
size_t get_size(const std::string& message);

/**
 * \brief Вывод в строку элементов массива
 * \param cols количество строк в массиве
 * \param rows количество столбцов в массиве
 * \return Строка с элементами
 */
string to_string(int**, const size_t cols, const size_t rows);

/**
 * \brief Заменяет элементы кратные 3 на 0
 * \param cols количество строк в массиве
 * \param rows количество столбцов в массиве
 */
void replace_multiple_three(int**, const size_t cols, const size_t rows);

/**
 * \brief Удаляет строки в которых второй элемент больше предпоследнего
 * \param cols количество строк в массиве
 * \param rows количество столбцов в массиве
 */
void delete_cols(int**&, size_t& cols, size_t rows);

/**
 * \brief Удаляет строку под номером (\a index)
 * \param cols количество строк в массиве
 * \param rows количество столбцов в массиве
 * \param index номер строки которую надо удалить
 */
void delete_col(int**&, size_t& cols, size_t rows, const size_t index);


/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
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
        cols = get_size("Введите количество строк массива = ");
        rows = get_size("Введите количество столбцов массива = ");
        cout << "Выберите способ создания массива: " << static_cast<int>(InputType::MANUALLY) << " - вручную, " << static_cast<int>(InputType::RANDOMLY) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_matrix = get_matrix(cols, rows, input_type, LOWER_BOUND, UPPER_BOUND);
        cout << "Полученный массив:\n";
        cout << to_string(my_matrix, cols, rows);
        replace_multiple_three(my_matrix, cols, rows);
        cout << "Массив после замены всех элементов кратных 3 на 0:\n";
        cout << to_string(my_matrix, cols, rows);
        delete_cols(my_matrix, cols, rows);
        cout << "Массив после удаления всех строк в которых второй элемент больше предпоследнего:\n";
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
        throw out_of_range("Неправильный размер массива");

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
                cout << "Введите matrix[" << col << "][" << row <<"] = ";
                cin >> matrix[col][row];
                break;
            }
            case static_cast<int>(InputType::RANDOMLY):
            {
                matrix[col][row] = uniformIntDistribution(gen);
                break;
            }
            default:
                cout << "Ошибка!";
            }
        }
    }

    return matrix;
}

string to_string(int** matrix, const size_t cols, const size_t rows)
{
    if (matrix == nullptr)
        throw invalid_argument("Массив не существует");

    stringstream buffer;
    if (cols == 0)
        buffer << "{}";
    else {
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