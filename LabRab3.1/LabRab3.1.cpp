#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int count=1; 
    int y;
    int* arr;
    int size;
    cout << "Введите количество элементов массива: ";
    cin >> size;
    if (size <= 0) {
        cerr << "Неправильный размер" << endl;
        return 1;

    }
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "На данный момент массив состоит из  " << i << "  элементов, введите     " << count << "  значение" << endl;
        cin >> arr[i];
        count++;
    }
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; 

    return 0;
}
    
    
    
       
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    