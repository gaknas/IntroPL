#include <iostream>

/**
 * \brief ��������� ����������� ����� �� �������.
 * \param message ������������� ��������� ��� ������������.
 * \return ����������� �����.
 */
int read_number(const std::string& message);

/**
 * \brief ������� ���������� �� ����������� ����/���� �����.
 * \param a ������ �����.
 * \param b ������ �����.
 * \param c ������ �����(���� c < 0 � ���������� ��� �� ����������).
 * \return 0 � ������ ������.
 */
int ascendingSort(double& a, double& b, double& c);

/**
 * \brief ������� ���������� ������������ �� ���� �����.
 * \param a ������ �����.
 * \param b ������ �����.
 * \param c ������ �����.
 * \return ����������� �� ���� �����.
 */
double getMinimum(double a, double b, double c);

/**
 * \brief ������� ���������� ������������� �� ���� �����.
 * \param a ������ �����.
 * \param b ������ �����.
 * \param c ������ �����.
 * \return ������������ �� ���� �����.
 */
double getMaximum(double a, double b, double c);

/**
 * \brief ������, ���������� �� �������� � �������� ����� \a x.
 * \param x �������� �����.
 * \return true, ���� �������� ��������� � �������� ����� \a x ����������.
 */
bool isCalculated(double x);

/**
 * \brief ����� ����� � ���������.
 * \return 0 � ������ ������.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        const auto NUMBER = read_number("������� ����� ");
        double sine = sin(NUMBER);
        std::cout << "����� ����� ����� " << sine << "\n";
        double cosine = cos(NUMBER);
        std::cout << "������� ����� ����� " << cosine << "\n";
        double logarithm = -1;
        if (isCalculated(NUMBER)) {
            logarithm = log(NUMBER);
            std::cout << "�������� ����� ����� " << logarithm << "\n";
        }
        else {
            std::cout << "�������� �� �����������" << "\n";
        }
        ascendingSort(sine, cosine, logarithm);
        std::cout << sine << " " << cosine << " " << logarithm << std::endl;
        return 0;
    }
    catch (...)
    {
        return 1;
    }
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

int ascendingSort(double &a, double &b, double &c)
{
    if (c < 0) {
        if (a > b) {
            double auxiliary = a;
            a = b;
            b = auxiliary;
        }
    }
    else {
        const double summ = a + b + c;
        a = getMinimum(a, b, c);
        c = getMaximum(a, b, c);
        b = summ - a - c;
    }
    return 0;
}

int read_number(const std::string& message)
{
    std::cout << message;
    int number = 0;
    std::cin >> number;
    return number;
}

bool isCalculated(const double x)
{
    return x > 0;
}