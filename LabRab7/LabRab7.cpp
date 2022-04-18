#include <iostream>
#include <string>
#include "Pair.h"
#define SIZE 20 
using namespace std;

template <typename Type>


void quickSort(Type* numbers, int left, int right)
{
    Type pivot; 
    int l_hold = left; 
    int r_hold = right;
    pivot = numbers[left];
    while (left < right) 
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; 
        if (left != right) 
        {
            numbers[left] = numbers[right]; 
            left++; 
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right) 
        {
            numbers[right] = numbers[left]; 
            right--; 
        }
    }

    numbers[left] = pivot; 
    int newgran = left;
    left = l_hold;
    right = r_hold;
    if (left < newgran) 
        quickSort(numbers, left, newgran - 1);
    if (right > newgran)
        quickSort(numbers, newgran + 1, right);
}


template <typename Type>
void print(Type a[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

}





int main()
{
    setlocale(LC_ALL, "rus");
    int a[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 201 - 100;

    }
    cout << "Быстрая сортировка int\n";
    print<int>(a);
    quickSort<int>(a, 0, SIZE - 1);
    print<int>(a);
    double b[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = rand() % 201 - 100;

    }
    cout << endl;
    cout << "Быстрая сортировка double\n";
    print<double>(b);
    quickSort<double>(b, 0, SIZE - 1); 
    print<double>(b);
    char c[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        c[i] = char(rand() % 100 + 32);

    }
    cout << endl;
    cout << "Быстрая сортировка char\n";
    print<char>(c);
    quickSort<char>(c, 0, SIZE - 1); 
    print<char>(c);
   
    Pair p[5];
    cout << endl;
    cout << "Заданные данные\n";
    p[0] = { "Ivanov", 42 };
    p[1] = { "Pertov", 50 };
    p[2] = { "Simonov", 23 };
    p[3] = { "Rostova", 41 };
    p[4] = { "Kokina", 15 };
    for (int i = 0; i < 5; i++)
    {
        p[i].show();
    }
    cout << endl;
    cout << "Быстрая сортировка по возрасту\n";
    quickSort<Pair>(p, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        p[i].show();
    }
    cout << endl;


}

