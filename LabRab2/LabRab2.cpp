#include <iostream>
#include <clocale>



using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    int i = 100;
    int n;
    int factn = 1;
    int z = 0;
    int k;
    int factk = 1;
    int factnk = 1;
    int summ = 0;
    int x = 505;
    int summ2 = 0;
    int schet = 0;
    while (i != 4)
    {
        printf("Введите 1 для построения числового треугольника. \n");
        printf("Введите 2 для нахождения биномиальных коэффициентов. \n");
        printf("Введите 3 для вычисление среднего арифметического введенных точек. \n");
        printf("Введите 4 для выхода. \n");
        cin >> i;
        if (i == 1)
        {
            printf("Введите длину основания треугольника: ");
            int h;
            cin >> h;
            for (int g = 0; g <= h; g++)
            {
                int y;
                for (y = 0; y <= g; y++)
                {
                    cout << y;
                }
                cout << "\n";
            }
        }   cout << "\n";
        if (i == 2)
        {
            printf("Введите значение n: ");
            cin >> n;
            for (z = 1; z <= n; z++)
            {
                factn *= z;
            }
            printf("Введите значение k: ");
            cin >> k;
            for (z = 1; z <= k; z++) {
                factk *= z;
            }
            for (z = 1; z <= (n - k); z++) {
                factnk *= z;
            }
            summ = (factn / (factk * factnk));
            cout << "Ответ:" << summ << "\n";
            cout << "\n";
        }
        if (i == 3)
        {
            printf("Введите произвольное количество координат: \n");
            printf("Чтобы завершить ввод координат - введите 0 \n");
            while (x != 0)
            {

                cin >> x;
                if (x != 0)
                {
                    summ2 += x;
                    schet += 1;
                }
                else
                {
                    z = (summ2 / schet);
                    cout << "Среднее арифметическое: " << z << "\n";
                    cout << "\n";
                }


            }

        }
    }
    return 0;
}