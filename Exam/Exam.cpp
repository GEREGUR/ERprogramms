#include <iostream>
#include <cstring>
#include <clocale>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

void Zashifrovka() {
    int n, * sdvig;
    string text, copy;
    cin.ignore();
    cout << "\nЗадача 1. Зашифровать текст задания и расшифровать.\n";
    cout << "Введите текст для зашифровки: ";
    getline(cin, text);
    copy = text;
    cout << "Введите размер последовательности sdvig: ";
    cin >> n;

    sdvig = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент последовательности #" << (i + 1) << " в диапазоне [-1000;1000]: ";
        cin >> sdvig[i];
        if ((sdvig[i] < -1000)  (sdvig[i] > 1000)) {
            cout << "Элемент выходит за диапазон!";
            i--;
        }
    }

    for (int i = 0; i < text.length(); i++) {

        if (i < text.length() - text.length() % n) {
            if (isalpha(text[i])) {
                cout << "Преобразовали символ " << text[i];
                int pos = i % n;

                bool isUpper = isupper(text[i]);
                if (isUpper) text[i] = tolower(text[i]);

                if (sdvig[pos] >= 0)
                    text[i] = (text[i] - 'a' + sdvig[pos]) % 26 + 'a';
                else
                    text[i] = (text[i] - 'a' + 26 + sdvig[pos]) % 26 + 'a';

                if (isUpper) text[i] = toupper(text[i]);

                cout << " в символ " << text[i] << " со сдвигом " << sdvig[pos] << "\n";
            }
        }
        else {
            if (i == text.length() - text.length() % n)
                cout << "\nС этого символа остаётся блок длиною менее n, сдвигаем его на величину 123 по циклу алфавита\n\n";
            if (isalpha(text[i])) {
                cout << "Преобразовали символ " << text[i];
                int pos = 123;

                bool isUpper = isupper(text[i]);
                if (isUpper) text[i] = tolower(text[i]);

                text[i] = (text[i] - 'a' + 26 + pos) % 26 + 'a';

                if (isUpper) text[i] = toupper(text[i]);

                cout << " в символ " << text[i] << " со сдвигом " << pos << "\n";
            }
        }
    }

    cout << "Текст до зашифровки: " << copy << "\n";
    cout << "Текст после зашифровки: " << text << "\n";

    cout << "\n\nРасшифруем зашифрованный текст\n\n";
    copy = text;
    for (int i = 0; i < n; i++) {
        sdvig[i] = -sdvig[i];
    }
    for (int i = 0; i < text.length(); i++) {

        if (i < text.length() - text.length() % n) {
            if (isalpha(text[i])) {
                cout << "Преобразовали символ " << text[i];
                int pos = i % n;

                bool isUpper = isupper(text[i]);
                if (isUpper) text[i] = tolower(text[i]);

                if (sdvig[pos] >= 0)
                    text[i] = (text[i] - 'a' + sdvig[pos]) % 26 + 'a';
                else
                    text[i] = (text[i] - 'a' + 26 + sdvig[pos]) % 26 + 'a';

                if (isUpper) text[i] = toupper(text[i]);

                cout << " в символ " << text[i] << " со сдвигом " << sdvig[pos] << "\n";
            }
        }
        else {
            if (i == text.length() - text.length() % n)
                cout << "\nС этого символа остаётся блок длиною менее n, сдвигаем его на величину -123 по циклу алфавита\n\n";
            if (isalpha(text[i])) {
                cout << "Преобразовали символ " << text[i];
                int pos = (-123 % 26);

                bool isUpper = isupper(text[i]);
                if (isUpper) text[i] = tolower(text[i]);

                text[i] = (text[i] - 'a' + 26 + pos) % 26 + 'a';

                if (isUpper) text[i] = toupper(text[i]);

                cout << " в символ " << text[i] << " со сдвигом " << pos << "\n";
            }
        }
    }

    cout << "Текст до расшифровки: " << copy << "\n";
    cout << "Текст после расшифровки: " << text << "\n";

    ofstream encr;
    encr.open("task_encript.txt");
    ofstream decr;
    decr.open("task_decript.txt");

    encr << "Зашифрованный текст: " << copy;
    encr.close();
    decr << "Расшифрованный текст: " << text;
    decr.close();

    cout << "\nТексты записаны в файлы task_encript и task_decript\n";
}

void DlinaLomanoy() {
    float** coords;
    float length = 0;
    int n;

    cout << "\nЗадача 2. По заданной последовательности двумерных координат вычислить длину ломаной.\n";
    cout << "Введите количество точек ломаной: ";
    cin >> n;

    coords = new float* [n];
    for (int i = 0; i < n; i++) {
        coords[i] = new float[2];

        cout << "Введите X Y координаты точки #" << (i + 1) << ": ";
        cin >> coords[i][0] >> coords[i][1];
    }

    for (int i = 0; i < n - 1; i++) {
        length += sqrt((coords[i + 1][0] - coords[i][0]) * (coords[i + 1][0] - coords[i][0]) + (coords[i + 1][1] - coords[i][1]) * (coords[i + 1][1] - coords[i][1]));
    }

    cout << "\nДлина ломаной = " << length << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = -1;

    while (choice != 0) {
        cout << "\nГлавное меню:\n";
        cout << "1. Задача 1. Зашифровка текста.\n";
        cout << "2. Задача 2. Длина ломаной.\n";
        cout << "0. Выход из приложения.\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice < 0  choice > 2) {
            cout << "\nНЕВЕРНЫЙ ВВОД\n";
        }
        else {
            switch (choice) {
            case 0:
                cout << "\nЗавершение работы...";
                break;
            case 1:
                Zashifrovka();
                break;
            case 2:
                DlinaLomanoy();
                break;
            }
        }
    }

    return 0;
}