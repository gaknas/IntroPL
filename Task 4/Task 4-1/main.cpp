#include <iostream>
#include <sstream>
#include <random>

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
 * \param size Размер массива
 * \param input_type Способ создания массива
 * \param LOWER_BOUND Нижняя граница для случайных чисел
 * \param UPPER_BOUND Верхняя граница для случайных чисел
 * \return Заполненный массив
 */
int* get_array(const size_t size, const int input_type, const int LOWER_BOUND, const int UPPER_BOUND);

/**
 * \brief Функция для получения размера массива
 * \param message Мотивоционное сообщение для пользователя
 * \return Размер массива
 */
size_t get_size(const std::string& message);

/**
 * \brief Вывод в строку элементов массива
 * \param size Размер массива
 * \return Строка с элементами
 */
string to_string(const int*, const size_t size);

/**
 * \brief Находит произведение четных элементов, значение которых по модулю меньше 5
 * \param size Размер массива
 * \return Произведение элементов
 */
int get_even_composition(int*, const size_t size);

/**
 * \brief Находит количество нечетных элементов по модулю превышающих заданное число (\a A)
 * \param size Размер массива
 * \param A Число A
 * \return Количество элементов
 */
int get_odd_quantity(int*, const size_t size, const int A);

/**
 * \brief Умножает все нечетные элементы массива кратные 3 на их номер
 * \param size Размер массива
 * \return Количество элементов
 */
void multiply_elements(int*, const size_t size);


/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int LOWER_BOUND = -11;
    const int UPPER_BOUND = 21;
    try
    {
        const auto size = get_size("Введите размер массива = ");
        cout << "Выберите способ создания массива: " << static_cast<int>(InputType::MANUALLY) << " - вручную, " << static_cast<int>(InputType::RANDOMLY) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_array = get_array(size, input_type, LOWER_BOUND, UPPER_BOUND);
        cout << "Полученный массив:\n";
        cout << to_string(my_array, size);
        cout << "\nПроизведение четных элементов, значение которых по модулю меньше 5 = " << get_even_composition(my_array, size) << '\n';
        cout << "Введите число A = ";
        int A;
        cin >> A;
        cout << "Количество нечетных элементов по модулю превышающих заданное число (A) = " << get_odd_quantity(my_array, size, A) << '\n';
        cout << "Массив после умножаения всех нечетных элементов массива кратных 3 на их номер:\n";
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
        throw out_of_range("Неправильный размер массива");

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
            cout << "Введите " << index + 1 << " элемент массива = ";
            cin >> array[index];
            break;
        }
        case static_cast<int>(InputType::RANDOMLY):
        {
            array[index] = uniformIntDistribution(gen);
            break;
        }
        default:
            cout << "Ошибка!";
        }
    }

    return array;
}

string to_string(const int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

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
