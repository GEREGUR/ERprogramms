#include <iostream>
#include "Matrix3DG.h"

using namespace std;

int main()
{
    setlocale(0, "rus");
    double tr;
    int z;
    cout << "Введите размер матрицы: ";
    cin >> z;
    cout << "Работает конструктор\n";
    Matrix3DG matr1 = Matrix3DG(z);
    cout << "";
  
    cout << "Введите Трехдиагональную матрицу\n";
    matr1.input();
  
    matr1.print();
    tr = matr1.trace();
    cout << "След = " << tr << endl;
    cout << "Определитель матриц " << matr1.det() << endl;
    cout << matr1.get_n(); 
    cout << matr1 << endl;
    Matrix3DG matr2 = Matrix3DG(8);
    matr2.inputRand();
    cin >> matr2;
    cout << matr1 << matr2 << endl;

}

