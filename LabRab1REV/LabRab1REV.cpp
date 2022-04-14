#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int m;
    cout << "Введите любую цифру: ";
    cin >> m;
    cout << "Рубайло Егор Васильевич 211-352\n";
    cout << "\n";
    cout << "Введите любую цифру: ";
    cin >> m;
    cout << "min int = " << INT_MIN << ", max int = " << INT_MAX << ", size of int = " << sizeof(int) << "\n";
    cout << "min unsigned int = " << 0 << ", max unsigned int = " << UINT_MAX << ", size of unsigned int = " << sizeof(unsigned int) << "\n";
    cout << "min short = " << SHRT_MIN << ", max short = " << SHRT_MAX << ", size of short = " << sizeof(short) << "\n";
    cout << "min unsigned short = " << 0 << ", max unsigned short = " << USHRT_MAX << ", size of unsigned short = " << sizeof(unsigned short) << "\n";
    cout << "min long = " << LONG_MIN << ", max long = " << LONG_MAX << ", size of long = " << sizeof(long) << "\n";
    cout << "min long long = " << LLONG_MIN << ", max long long = " << LLONG_MAX << ", size of long long = " << sizeof(long long) << "\n";
    cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ", size of double = " << sizeof(double) << "\n";
    cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ", size of char = " << sizeof(char) << "\n";
    cout << "min bool = " << 0 << ", max bool = " << (pow(2, sizeof(bool) * 8.0) - 1) << ", size of bool = " << sizeof(bool) << "\n";
    cout << "\n";
    cout << "Введите любую цифру: ";
    cin >> m;
    int a;
    int b;
    int x;
    cout << "Введите a (a!=0): ";
    cin >> a;
    if (a == 0)
    {
        while (a == 0) {
            cout << "Ошибка! Введите ещё раз, а не должно равняться нулю: ";
            cin >> a;
        }
    }
    cout << "Введите b: ";
    cin >> b;
    cout << "x = " << b / a << "\n";
    cout << "\n";
    cout << "Введите любую цифру: ";
    cin >> m;
    cout << "Задайте начало отрезка: ";
    cin >> a;
    cout << "Задайте конец: ";
    cin >> b;
    if (a > b) // Выявляем начало отрезка.
    {
        x = (a - b) / 2;
        if (a % 2 == b % 2) {
            cout << b + x << " - Середина отрезка";
        }
        else {
            cout << (b + x) + 0.5 << " - Середина отрезка";

        }
    }
    else
    {
        x = (b - a) / 2;
        if (a % 2 == b % 2)
        {
            cout << a + x << " - Середина отрезка";
        }
        else
        {
            cout << (a + x) + 0.5 << " - Середина отрезка";

        }

    }



}