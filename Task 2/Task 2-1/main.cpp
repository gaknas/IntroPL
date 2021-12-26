#include <iostream>
#include <string>

using namespace std;

/**
 * \brief Перечислимый тип видов сортировок.
 */
enum class SortType
{
    /**
     * \brief сортировка по возрастанию.
     */
    ascending,

     /**
      * \brief сортировка по убыванию.
      */
    descending
};

/**
 * \brief Функция сортировки по возрастанию трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return 0 в случае успеха.
 */
int ascendingSort(double &a, double &b, double &c);

/**
 * \brief Функция сортировки по убыванию трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return 0 в случае успеха.
 */
int descendingSort(double &a, double &b, double &c);

/**
 * \brief Функция нахождения минимального из трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return минимальное из трех чисел.
 */
double getMinimum(double a, double b, double c);

/**
 * \brief Функция нахождения максимального из трех чисел.
 * \param a первое число.
 * \param b второе число.
 * \param c третье число.
 * \return максимальное из трех чисел.
 */
double getMaximum(double a, double b, double c);

/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Выберите как сортировать числа: " << static_cast<int>(SortType::ascending) << " - по возрастанию, " << static_cast<int>(SortType::descending) << " - по убыванию ";

    int sort_type;
    cin >> sort_type;

    switch (sort_type)
    {
    case static_cast<int>(SortType::ascending):
    {
        cout << "Введите первое число: ";
        double a;
        cin >> a;
        cout << "Введите второе число: ";
        double b;
        cin >> b;
        cout << "Введите третье число: ";
        double c;
        cin >> c;
        ascendingSort(a, b, c);
        cout << a << " " << b << " " << c << endl;
        break;
    }
    case static_cast<int>(SortType::descending):
    {
        cout << "Введите первое число: ";
        double a;
        cin >> a;
        cout << "Введите второе число: ";
        double b;
        cin >> b;
        cout << "Введите третье число: ";
        double c;
        cin >> c;
        descendingSort(a, b, c);
        cout << a << " " << b << " " << c << endl;
        break;
    }
    default:
        cout << "Ошибка!";
    }

    return 0;
}

int ascendingSort(double &a, double &b, double &c)
{
    const double summ = a + b + c;
    const double min = getMinimum(a, b, c);
    const double max = getMaximum(a, b, c);
    a = min;
    c = max;
    b = summ - a - c;
    return 0;
}


int descendingSort(double &a, double &b, double &c)
{
    const double summ = a + b + c;
    const double min = getMinimum(a, b, c);
    const double max = getMaximum(a, b, c);
    c = min;
    a = max;
    b = summ - a - c;
    return 0;
}

double getMinimum(double a, double b, double c)
{
    if (a > b) a = b;
    if (a > c) a = c;
    return a;
}

double getMaximum(double a, double b, double c)
{
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}