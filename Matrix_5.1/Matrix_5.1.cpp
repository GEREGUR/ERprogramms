
#include "Matrix.h"
#include <iostream>
#include <iomanip>
	using namespace std;

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
void Matrix::input() 
	cout << "Ввод матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cin >> *(a + columns * i + j); 

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
//--------------------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------------------------
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
Matrix* Matrix::sum(const Matrix* mat2)
{
	if (this->columns != mat2->columns || this->rows != mat2->rows)
	{
		cout << "Матрицы не могут быть сложенны\n";
		cout << "Не соответствие по размерам.";
		return nullptr;
	}
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

			*(matrmult->a + i * columns + j) = *(this->a + i * columns + j) + *(mat2->a + i * columns + j);
		}
	}
	return matrmult;
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
====== =
#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
void Matrix::input()
{
	cout << "Ввод матрицы" << endl;
	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> columns;
	a = new double[rows * columns]; 
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cin >> *(a + columns * i + j); 

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
//--------------------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------------------------
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
Matrix* Matrix::sum(const Matrix* mat2)
{
	if (this->columns != mat2->columns || this->rows != mat2->rows)
	{
		cout << "Матрицы не могут быть сложенны\n";
		cout << "Не соответствие по размерам.";
		return nullptr;
	}
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

			*(matrmult->a + i * columns + j) = *(this->a + i * columns + j) + *(mat2->a + i * columns + j);
		}
	}
	return matrmult;
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

