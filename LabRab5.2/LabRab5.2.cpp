<<<<<< < HEAD
    ﻿
#include <iostream>
#include "Matrix.h"
    using namespace std;

int main()
{
    int z;
    setlocale(LC_ALL, "rus");
    cout << "Для старта программы введите любую цифру" << endl;
    cin >> z;
    double* arr = create_rand_arr();
    print_arr(arr, 12);
    cout << "Для запуска конструктора, использующего элементы массива введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr10(3, 4, arr, 12);
    matr10.print();
    
    cout << "Для запуска конструктора с нулевыми элементами и сложения матриц введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr5(3, 4); 
    matr5.print();
    Matrix* pmatr11;
    pmatr11 = matr5.sum(arr, 12);
    pmatr11->print();
    

    cout << "Для запуска Умножения матриц введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr1;
    Matrix* pmatr12;
    matr1.inputRand();
    matr1.print();
    pmatr12 = matr1.matrmult(arr, 12);
    pmatr12->print();
    
    cout << "Для ввода матрицы в ручную введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr8;
    matr8.input(3, 4);
    matr8.print();
    
    cout << "Для инициализации матрицы заданным массивом введите любую цифру" << endl;
    cin >> z;
   
    Matrix matr7;
    matr7.input(3, 4, arr);
    matr7.print();
    







    return 0;
}





====== =
﻿
#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    int z;
    setlocale(LC_ALL, "rus");
    cout << "Для старта программы введите любую цифру" << endl;
    cin >> z;
    double* arr = create_rand_arr();
    print_arr(arr, 12);
    cout << "Для запуска конструктора, использующего элементы массива введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr10(3, 4, arr, 12);
    matr10.print();
    
    cout << "Для запуска конструктора с нулевыми элементами и сложения матриц введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr5(3, 4); 
    matr5.print();
    Matrix* pmatr11;
    pmatr11 = matr5.sum(arr, 12);
    pmatr11->print();
    cout << "Для запуска Умножения матриц введите любую цифру" << endl;
    cin >> z;
    
    Matrix matr1;
    Matrix* pmatr12;
    matr1.inputRand();
    matr1.print();
    pmatr12 = matr1.matrmult(arr, 12);
    pmatr12->print();
    
    cout << "Для ввода матрицы в ручную введите любую цифру" << endl;
    cin >> z;
  
    Matrix matr8;
    matr8.input(3, 4);
    matr8.print();
    
    cout << "Для инициализации матрицы заданным массивом введите любую цифру" << endl;
    cin >> z;

    Matrix matr7;
    matr7.input(3, 4, arr);
    matr7.print();
   







    return 0;
}


