#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int y;
    cout << "Для старта введите любую цифру: ";
    cin >> y;
    cout << "Будет выполнено: Ввод матрыцы с клавиатуры, количество столбцов, количество строк и печать матрицы в консоль\n";


    Matrix matr1;

    matr1.input();
    cout << matr1.get_rows() << " Количество строк" << endl;
    cout << matr1.get_columns() << " Количество столбцов" << endl;
    matr1.print();

    cout << "Для вывода конкретного элемента введите любую цифру: ";
    cin >> y;
    int i, j;
    cout << "Введите строку: ";
    cin >> i;
    cout << "Введите столбец: ";
    cin >> j;

    cout << matr1.get_element(i, j) << endl;

    cout << "Для вывода суммы диагональных элементов матрицы введите любую цифру: ";
    cin >> y;

    cout << matr1.trace() << "  Сумма диагональных элементов матрицы" << endl;

    cout << "Для умножения матрицы на число введите любую цифру: ";
    cin >> y;

    int z;
    cout << "Умножить на число: ";
    cin >> z;
    Matrix* pmatr2 = matr1.mult_by_num(z);
    pmatr2->print();

    cout << "Для перемножения двух матриц введите любую цифру: ";
    cin >> y;

    Matrix mat2;
    mat2.inputRand();
    mat2.print();
    Matrix* pmatr3 = matr1.matrmult(&mat2);
    pmatr3->print();
    cout << "Для сложения матриц введите любую цифру: ";
    cin >> y;

    Matrix* pmatr4 = matr1.sum(&mat2);
    pmatr4->print();
    cout << "Для вывода определителя матрицы введите любую цифру: ";
    cin >> y;

    cout << matr1.det();
    return 0;
}