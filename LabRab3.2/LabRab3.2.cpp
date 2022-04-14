#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x = 0, y = 0, z = 0;
    int arr[1000];
    int arr2[1000];
    int w = 0;
    int summ = 0;
    int w1 = 0;
    int chet = 2;
    bool z1 = false;
    int shet;
    int dub;


    while (true)
    {
        cout << "Выберите действие" << endl;
        cout << " 1 - Создать массив\n 2 - Вывод введённого массива\n 3 - Сортировка по сумме цифр, стоящих на четных местах\n 4 - Выход \n";
        cin >> x;
        if (x == 1)
        {
           
            cout << "Задайте длину массива: ";
            cin >> z;
            cout << "Задайте значение массива\n";
            for (int i = 0; i < z; i++)
            {
                cin >> y;
                arr[i] = y;
            }
            z1 = true;
            
        }
        if (x == 2 && z1 == true)
        {
            
            cout << "Массив выведен\n";
            cout << "\n";
            for (int i = 0; i < z; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            
        }
        else if (x == 2 && z1 == false)
        {
            cout << "Ошибка, для начала нужно создать массив" << endl;
            
        }
        if (x == 3 && z1 == true)
        {
            cout << "Массив отсортирован\n";
            cout << "\n";
            for (int i = 0; i < z; i++)

            {
                w1 = arr[i];
                if (w1 % 2 == 0)
                {
                    chet = 2;
                }
                else
                {
                    chet = 1;
                }
                summ = 0;
                while (w1 > 0)
                {

                    if (chet % 2 == 0)
                    {
                        w = w1 % 10;
                        w1 = w1 / 10;
                        summ += w;
                        chet += 1;
                    }
                    else
                    {
                        w1 = w1 / 10;
                        chet += 1;
                    }
                }
                arr2[i] = summ;


            }
            for (int i = 0; i < z; i++)
                for (int j = 0; j < z - 1; j++)
                {
                    if (arr2[j] > arr2[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                        swap(arr2[j], arr2[j + 1]);
                    }
                }
            for (int i = 0; i < z; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (x == 3 && z1 == false)
        {
            cout << " Ошибка, для начала нужно создать массив" << endl;

        }

        if (x == 4)
            break;

    }
}