#include <iostream>
#include <bitset>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
void task1()
{
    int n, d, d1, p;
    cout << "введите число" << endl;
    cin >> n;
    d = 0;
    d1 = 0;
    p = 0;

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= i; k++) {

            cout << k;
        }
        cout << endl;
    }
}
void task2()
{
    int n, c;
    cout << "введите положительное целое число" << endl;
    cin >> n;
    if (n > 0) {
        c = n;
        for (int k = 1; k <= n; ++k) {
            cout << c << endl;
            c *= (n - k);
            c /= (k + 1);

        }


    }



}
void task3()
{
    double sum = 0, key;
    int k = 0;
    cout << "Вводите числа(0-stop)" << endl;
    cin >> key;
    while (key != 0) {

        k++;
        sum += key;
        cin >> key;

    }

    cout << sum / k << endl;
}
int main()
{
    setlocale(LC_ALL, "russian");
    int choice = 0;
    while (true)
    {
        cout << "Что вы хотите выполнить, напишите номер задания? \n"
            << " задание 1 " << " задание 2 " << " задание 3 " << " выход ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {

            task1();
            break;
        }
        case 2:
        {

            task2();
            break;
        }
        case 3:
        {

            task3();
            break;

        }
        default:
        {
            return 0;
        }
        }
    }
}
