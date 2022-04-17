#include <iostream>
#include <deque>

using namespace std;

int main()
{

    setlocale(LC_ALL, "rus");
    deque <char> deq;
    int g;
    cout << "Введите количество элементов: ";
    cin >> g;
    char l;
    cout << "Введите элементы по одному\n";
    for (int i = 0; i < g; i++)
    {
        cin >> l;
        deq.push_back(l);
    }
  
    auto start = deq.begin();
    auto finish = deq.end() - 1;
    bool flag = true;
    while (start != finish)
    {
        if ((*start) != (*finish))
        {
            flag = false;
            break;
        }
        else
        {
            deq.pop_back();
            deq.pop_front();
        }
        start = deq.begin();
        finish = deq.end() - 1;
    }
    if (flag == false)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

}


