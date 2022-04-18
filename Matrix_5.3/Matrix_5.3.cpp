#include "Matrix3DG.h"
#include <iostream>
#include <iomanip>
using namespace std;

Matrix3DG::Matrix3DG(int n) : n(n) 
{
	if (n <= 0)
	{
		a = nullptr;
		return;
	}
	
	int size = 3 * n - 2;
	this->a = new double[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = 1;
	}

}
double Matrix3DG::get_elem(int i, int j) 
{
	if (j<(i - 1) || j >(i + 1))
	{
		return 0; 
	}
	
	if (i == 0)
	{
		return *(a + j);
	}
	return *(a + 2 * i + j);
}
int Matrix3DG::get_n()
{
	return n;
}




void Matrix3DG::print()
{
	cout << "--------------Матрица-------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << get_elem(i, j); 
		cout << endl;
	}

	cout << "----------------------------------------------------" << endl;
}

void Matrix3DG::input() 
{
	cout << "Введите размер матрицы: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Размер введёт некоректно" << endl;
		return;
	}
	int size = 3 * n - 2;
	this->a = new double[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];

	}

}

void Matrix3DG::inputRand(int n)
{
	if (n <= 0)
	{
		cout << "Размер введёт некоректно" << endl;
		return;
	}
	this->n = n;
	int size = 3 * n - 2;
	this->a = new double[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9 + 1;

	}
}
ostream& operator << (ostream& out, Matrix3DG& matr)
{
	matr.print();
	out << "Размер: " << matr.get_n() << endl;
	out << "След: " << matr.trace() << endl;
	out << "Определитель: " << matr.det() << endl;
	return out;
}
istream& operator>> (istream& in, Matrix3DG& matr)
{
	matr.input();
	return in;
}






void Matrix3DG::inputRand()
{

	
	int size = 3 * n - 2;
	this->a = new double[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9 + 1;

	}
}
double Matrix3DG::trace() 
{

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += get_elem(i, i);
	}
	return sum;
}
double Matrix3DG::det() 
{
	if (a == nullptr)
	{
		cout << "Матрица пустая. Невозможно вычислить определитель" << endl;
		return 0;

	}
	if (n == 1)return a[0];
	
	double* alf = new double[n - 1];
	double* gamma = new double[n - 1];
	gamma[0] = this->get_elem(0, 0);
	alf[0] = -this->get_elem(0, 1) / gamma[0];
	for (int i = 1; i < n - 1; i++)
	{
		gamma[i] = this->get_elem(i, i) + this->get_elem(i, i - 1) * alf[i - 1];
		alf[i] = -this->get_elem(i, i + 1) / gamma[i];

	}
	gamma[n - 1] = this->get_elem(n - 1, n - 1) + this->get_elem(n - 1, n - 2) * alf[n - 2];
	double det = 1;
	
	for (int i = 0; i < n; i++)
	{
		det *= gamma[i];
	}

	return det;
}