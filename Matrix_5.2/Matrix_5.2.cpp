#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;



Matrix::Matrix(int rows, int columns) :rows(rows), columns(columns) 
{
	if (rows <= 0 || columns <= 0)
	{
		cout << "Некоректно заданные размеры матрицы" << endl;
		return;
	}
	cout << "Ввод матрицы" << endl;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = 0; 

}

Matrix::Matrix(int rows, int columns, const double* arr, int size_arr) 
{
	if (arr == nullptr)
	{
		cout << "ициализирующий массив пуст" << endl;
		return;
	}
	if (rows <= 0 || columns <= 0)
	{
		cout << "Некоректно заданные размеры матрицы" << endl;
		a = nullptr;
		return;
	}
	if (rows * columns != size_arr)
	{
		cout << "Некоректный размер" << endl;
		return;

	}
	this->rows = rows;
	this->columns = columns;
	this->a = new double[rows * columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(this->a + columns * i + j) = *(arr + columns * i + j);

}


Matrix::~Matrix()
{
	cout << endl;
	cout << "Идёт работа деструктора" << endl;
	delete[] a; 
	a = nullptr; 
}

int Matrix::get_rows() 
{
	return rows;
}
void Matrix::set_rows(int rows) 
{
	this->rows = rows; 

}
int Matrix::get_columns()
{
	return columns;
}
void Matrix::set_columns(int columns)
{
	this->columns = columns;
}
double Matrix::get_element(int i, int j) 
{
	return *(a + i * columns + j);

}

void Matrix::input(int rows, int columns) 
{
	cout << "Ввод матрицы" << endl;
	this->rows = rows;
	this->columns = columns;
	cout << "Количество строк: " << rows << endl;
	cout << "Количество столбцов: " << columns << endl;
	a = new double[this->rows * this->columns]; 
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			cin >> *(a + this->columns * i + j);
}
void Matrix::input(int rows, int columns, const double* arr) 
{
	cout << "Ввод матрицы" << endl;
	this->rows = rows;
	this->columns = columns;
	cout << "Количество строк: " << rows << endl;
	cout << "Количество столбцов: " << columns << endl;
	a = new double[this->rows * this->columns]; 
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			*(a + this->columns * i + j) = *(arr + columns * i + j); 


}
void Matrix::print()
{
	cout << "--------------Матрица-------------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(5) << *(a + columns * i + j); 
		cout << endl;
	}

	cout << "----------------------------------------------------" << endl;
}
void Matrix::inputRand() 
{
	cout << "Ввод матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = rand() % 10; 
}

double Matrix::trace() 
{
	if (rows != columns)
	{
		cout << "Матрица не квадратная" << endl;
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += *(a + i * columns + i);
	}
	return sum;
}

Matrix* Matrix::mult_by_num(double num) 
{
	
	Matrix* matrmult = new Matrix; 
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * this->columns];
	matrmult->rows = this->rows;
	matrmult->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(matrmult->a + i * columns + j) = num * (*(this->a + i * columns + j));
		}
	}
	cout << endl;
	cout << "      Матрица умножена на число " << num << endl;
	return matrmult;

}
Matrix* Matrix::matrmult(const Matrix* mat2)
{
	if (this->columns != mat2->rows)
	{
		cout << "Матрицы не могут быть перемноженны\n";
		cout << "Не соответствие по размерам. Размермер по столбцам первой матрицы должен совпадать с размерам по строкам с другой.";
		return nullptr;
	}
	Matrix* matrmult = new Matrix;  
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * mat2->columns];
	matrmult->rows = this->rows;
	matrmult->columns = mat2->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < mat2->columns; j++)
		{
			double sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += (*(this->a + i * columns + k)) * (*(mat2->a + k * mat2->columns + j));

			}
			*(matrmult->a + i * matrmult->columns + j) = sum;
		}
	}
	return matrmult;
}
Matrix* Matrix::matrmult(const double* arr, int size_arr)
{


	if (arr == nullptr || size_arr <= 0 || size_arr % this->columns != 0)
	{
		cout << "Некорректно задан массив.";
		return nullptr;
	}
	int arr_rows = this->columns;
	int arr_columns = size_arr / this->columns;
	Matrix* matrmult = new Matrix;  
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * arr_columns];
	matrmult->rows = this->rows;
	matrmult->columns = arr_columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < arr_columns; j++)
		{
			double sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += (*(this->a + i * columns + k)) * (*(arr + k * arr_columns + j));

			}
			*(matrmult->a + i * matrmult->columns + j) = sum;
		}
	}
	return matrmult;
}

Matrix* Matrix::sum(const Matrix* mat2)
{
	if (this->columns != mat2->columns || this->rows != mat2->rows)
	{
		cout << "Матрицы не могут быть сложенны\n";
		cout << "Не соответствие по размерам.";
		return nullptr;
	}
	Matrix* matrsum = new Matrix; 
	if (matrsum == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrsum->a = new double[this->rows * this->columns];
	matrsum->rows = this->rows;
	matrsum->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			*(matrsum->a + i * columns + j) = *(this->a + i * columns + j) + *(mat2->a + i * columns + j);
		}
	}
	return matrsum;
}
Matrix* Matrix::sum(const double* arr, int size)
{
	if (arr == nullptr || size <= 0 || this->rows * this->columns != size)
	{
		cout << "Некорректно задан массив.";
		return nullptr;
	}
	Matrix* matrsum = new Matrix; 
	if (matrsum == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrsum->a = new double[this->rows * this->columns];
	matrsum->rows = this->rows;
	matrsum->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			*(matrsum->a + i * columns + j) = *(this->a + i * columns + j) + *(arr + i * columns + j);
		}
	}
	return matrsum;
}
int Matrix::invers(int* a, int n)
{
	int i = 0;
	for (int x = 0; x < n; x++)
		for (int y = x + 1; y < n; y++)
			if (a[x] > a[y])
				i++;
	return i;
}
void Matrix::swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool Matrix::generation(int* a, int n)
{
	int j = n - 2;

	while (j != -1 && a[j] >= a[j + 1])
		j--;

	if (j == -1)
		return false;

	int k = n - 1;
	while (a[j] >= a[k])
		k--;

	swap(a, j, k);

	int l = j + 1, r = n - 1;
	while (l < r)
		swap(a, l++, r--);

	return true;
}
double Matrix::det() 
{
	if (this->a == nullptr)
	{
		cout << "Матрица пустая. Невозможно вычислить определитель" << endl;
		return 0;

	}
	if (this->rows != this->columns)
	{
		cout << "Матрица не квадратная. Невозможно вычислить определитель" << endl;
		return 0;
	}
	int n = rows;
	int* arrind = new int[n];

	for (int i = 0; i < n; i++)
		arrind[i] = i;

	int slag = n;                  
	for (int i = n - 1; i > 0; i--)
		slag *= i;

	double det = 0;
	for (int x = 0; x < slag; x++)
	{
		double temp = 1;
		for (int y = 0; y < n; y++)
			temp *= *(this->a + y * n + arrind[y]);

		det += temp * pow(-1, invers(arrind, n));

		generation(arrind, n);
	}
	

	delete[]arrind;
	return det;
}
double* create_rand_arr() 
{
	int rows, columns;
	cout << "Ввод массива матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	double* a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = rand() % 10; 

	return a;
}
void print_arr(double* arr, int size_arr)
{
	cout << "--------------Массив-------------------------------" << endl;
	for (int i = 0; i < size_arr; i++)
		cout << setw(5) << arr[i]; 
	cout << endl;

	cout << "----------------------------------------------------" << endl;
}
====== =
#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;



Matrix::Matrix(int rows, int columns) :rows(rows), columns(columns) 
{
	if (rows <= 0 || columns <= 0)
	{
		cout << "Некоректно заданные размеры матрицы" << endl;
		return;
	}
	cout << "Ввод матрицы" << endl;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = 0;

}

Matrix::Matrix(int rows, int columns, const double* arr, int size_arr)
{
	if (arr == nullptr)
	{
		cout << "ициализирующий массив пуст" << endl;
		return;
	}
	if (rows <= 0 || columns <= 0)
	{
		cout << "Некоректно заданные размеры матрицы" << endl;
		a = nullptr;
		return;
	}
	if (rows * columns != size_arr)
	{
		cout << "Некоректный размер" << endl;
		return;

	}
	this->rows = rows;
	this->columns = columns;
	this->a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(this->a + columns * i + j) = *(arr + columns * i + j);

}


Matrix::~Matrix()
{
	cout << endl;
	cout << "Идёт работа деструктора" << endl;
	delete[] a;
	a = nullptr; 
}

int Matrix::get_rows() 
{
	return rows;
}
void Matrix::set_rows(int rows) 
{
	this->rows = rows; 

}
int Matrix::get_columns()
{
	return columns;
}
void Matrix::set_columns(int columns)
{
	this->columns = columns;
}
double Matrix::get_element(int i, int j) 
{
	return *(a + i * columns + j);

}

void Matrix::input(int rows, int columns) 
{
	cout << "Ввод матрицы" << endl;
	this->rows = rows;
	this->columns = columns;
	cout << "Количество строк: " << rows << endl;
	cout << "Количество столбцов: " << columns << endl;
	a = new double[this->rows * this->columns]; 
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			cin >> *(a + this->columns * i + j); 

}
void Matrix::input(int rows, int columns, const double* arr) 
{
	cout << "Ввод матрицы" << endl;
	this->rows = rows;
	this->columns = columns;
	cout << "Количество строк: " << rows << endl;
	cout << "Количество столбцов: " << columns << endl;
	a = new double[this->rows * this->columns]; 
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			*(a + this->columns * i + j) = *(arr + columns * i + j); 


}
void Matrix::print()
{
	cout << "--------------Матрица-------------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(5) << *(a + columns * i + j); 
		cout << endl;
	}

	cout << "----------------------------------------------------" << endl;
}
void Matrix::inputRand() 
{
	cout << "Ввод матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = rand() % 10; 
}

double Matrix::trace() 
{
	if (rows != columns)
	{
		cout << "Матрица не квадратная" << endl;
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += *(a + i * columns + i);
	}
	return sum;
}

Matrix* Matrix::mult_by_num(double num) 
{
	
	Matrix* matrmult = new Matrix; 
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * this->columns];
	matrmult->rows = this->rows;
	matrmult->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(matrmult->a + i * columns + j) = num * (*(this->a + i * columns + j));
		}
	}
	cout << endl;
	cout << "      Матрица умножена на число " << num << endl;
	return matrmult;

}
Matrix* Matrix::matrmult(const Matrix* mat2)
{
	if (this->columns != mat2->rows)
	{
		cout << "Матрицы не могут быть перемноженны\n";
		cout << "Не соответствие по размерам. Размермер по столбцам первой матрицы должен совпадать с размерам по строкам с другой.";
		return nullptr;
	}
	Matrix* matrmult = new Matrix; 
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * mat2->columns];
	matrmult->rows = this->rows;
	matrmult->columns = mat2->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < mat2->columns; j++)
		{
			double sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += (*(this->a + i * columns + k)) * (*(mat2->a + k * mat2->columns + j));

			}
			*(matrmult->a + i * matrmult->columns + j) = sum;
		}
	}
	return matrmult;
}
Matrix* Matrix::matrmult(const double* arr, int size_arr)
{


	if (arr == nullptr || size_arr <= 0 || size_arr % this->columns != 0)
	{
		cout << "Некорректно задан массив.";
		return nullptr;
	}
	int arr_rows = this->columns;
	int arr_columns = size_arr / this->columns;
	Matrix* matrmult = new Matrix;
	if (matrmult == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrmult->a = new double[this->rows * arr_columns];
	matrmult->rows = this->rows;
	matrmult->columns = arr_columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < arr_columns; j++)
		{
			double sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += (*(this->a + i * columns + k)) * (*(arr + k * arr_columns + j));

			}
			*(matrmult->a + i * matrmult->columns + j) = sum;
		}
	}
	return matrmult;
}

Matrix* Matrix::sum(const Matrix* mat2)
{
	if (this->columns != mat2->columns || this->rows != mat2->rows)
	{
		cout << "Матрицы не могут быть сложенны\n";
		cout << "Не соответствие по размерам.";
		return nullptr;
	}
	Matrix* matrsum = new Matrix; 
	if (matrsum == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrsum->a = new double[this->rows * this->columns];
	matrsum->rows = this->rows;
	matrsum->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			*(matrsum->a + i * columns + j) = *(this->a + i * columns + j) + *(mat2->a + i * columns + j);
		}
	}
	return matrsum;
}
Matrix* Matrix::sum(const double* arr, int size)
{
	if (arr == nullptr || size <= 0 || this->rows * this->columns != size)
	{
		cout << "Некорректно задан массив.";
		return nullptr;
	}
	Matrix* matrsum = new Matrix; 
	if (matrsum == nullptr)
	{
		cout << "matrmult не выделена память" << endl;
	}
	matrsum->a = new double[this->rows * this->columns];
	matrsum->rows = this->rows;
	matrsum->columns = this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			*(matrsum->a + i * columns + j) = *(this->a + i * columns + j) + *(arr + i * columns + j);
		}
	}
	return matrsum;
}
int Matrix::invers(int* a, int n)
{
	int i = 0;
	for (int x = 0; x < n; x++)
		for (int y = x + 1; y < n; y++)
			if (a[x] > a[y])
				i++;
	return i;
}
void Matrix::swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool Matrix::generation(int* a, int n)
{
	int j = n - 2;

	while (j != -1 && a[j] >= a[j + 1])
		j--;

	if (j == -1)
		return false;

	int k = n - 1;
	while (a[j] >= a[k])
		k--;

	swap(a, j, k);

	int l = j + 1, r = n - 1;
	while (l < r)
		swap(a, l++, r--);

	return true;
}
double Matrix::det() 
{
	if (this->a == nullptr)
	{
		cout << "Матрица пустая. Невозможно вычислить определитель" << endl;
		return 0;

	}
	if (this->rows != this->columns)
	{
		cout << "Матрица не квадратная. Невозможно вычислить определитель" << endl;
		return 0;
	}
	int n = rows;
	int* arrind = new int[n];

	for (int i = 0; i < n; i++)
		arrind[i] = i;

	int slag = n;                 
	for (int i = n - 1; i > 0; i--)
		slag *= i;

	double det = 0;
	for (int x = 0; x < slag; x++)
	{
		double temp = 1;
		for (int y = 0; y < n; y++)
			temp *= *(this->a + y * n + arrind[y]);

		det += temp * pow(-1, invers(arrind, n));

		generation(arrind, n);
	}
	

	delete[]arrind;
	return det;
}
double* create_rand_arr() 
{
	int rows, columns;
	cout << "Ввод массива матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	double* a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(a + columns * i + j) = rand() % 10; 

	return a;
}
void print_arr(double* arr, int size_arr)
{
	cout << "--------------Массив-------------------------------" << endl;
	for (int i = 0; i < size_arr; i++)
		cout << setw(5) << arr[i]; 
	cout << endl;

	cout << "----------------------------------------------------" << endl;
}
>>>>>> > 1eeb851ededc0c51e6761726f5f05c01e650e0b0