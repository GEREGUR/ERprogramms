#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


bool Palindrom(char* str)
{

    int y = strlen(str) - 1;
    bool t = true;
    for (int i = 0, j = y; j >= 0 && i <= y; i++, j--)
    {
        if (str[i] == ' ')
            i++;
        if (str[j] == ' ')
            j--;
        if (str[i] != str[j]) {
            t = false;
            break;
        }

    }
    return t;
}
int find_substring1(const char* str_for_search_in, const char* substring, int start_position)
{
    int lenAllStr = 0;
    while (str_for_search_in[lenAllStr] != '\0')
        lenAllStr++;
    int lenSub = 0;
    while (substring[lenSub] != '\0')
        lenSub++;

    unsigned int i, j;
    int number = 0;
    for (i = start_position; i < lenAllStr - lenSub + 1; i++) {
        j = 0;
        while ((j < lenSub) && (substring[j] == str_for_search_in[i + j])) {
            j = j + 1;
        }

        if (j == lenSub)
        {
            return i;
        }

    }

    return number;


}
int* find_substring2(const char* str_for_search_in, const char* substring)
{
    int* mas = new int;

    int lenAllStr = 0;
    while (str_for_search_in[lenAllStr] != '\0')
        lenAllStr++;
    int lenSub = 0;
    while (substring[lenSub] != '\0')
        lenSub++;

    int i, j;
    int number = 0;
    for (i = 0; i < lenAllStr - lenSub + 1; i++) {
        j = 0;
        while ((j < lenSub) && (substring[j] == str_for_search_in[i + j])) {
            j = j + 1;
        }

        if (j == lenSub)
        {
            mas[number] = i;
            number++;
            cout << i << " ";
        }

    }

    return mas;

}

void encrypt(char* str_for_encrypt, int key)
{
    char ch;
    for (int i = 0; str_for_encrypt[i] != '\0'; ++i) {
        ch = str_for_encrypt[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            str_for_encrypt[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            str_for_encrypt[i] = ch;
        }
    }
    for (int i = 0; i <= sizeof(str_for_encrypt); i++)
        cout << str_for_encrypt[i];
    cout << endl;

}

void quotation_marks()
{
    string str, temp, text;
    cout << "Введите текст:";
    std::cin.ignore();
    getline(cin, text);
    long n, i, j = n = i = 0, flag = -1;


    while (text[i])
    {
        if ((text[i] == '"') || (text[i] == '«')) 
            if (flag < 0)
                flag = i; 
            else 
            {
                for (j = flag; j <= i; j++) cout << text[j];
                flag = -1; 
            }
        i++;
    }

}




void print_menu() {

    cout << "1. Палиндром" << endl;
    cout << "2. Поиск подстроки" << endl;
    cout << "3. Шифр" << endl;
    cout << "4. Найти слова в кавычках" << endl;
    cout << "5. Выход" << endl;
 
};

int get_variant(int count) {
    int variant;
    int s; 
    cin >> s; 
    while (s < 1 || s > count) {
        printf("Некоректный ввод. Введите снова: "); 
        cin >> s; 
    }
    variant = s;
    return variant;
};

int main()
{
    int variant;
    setlocale(LC_ALL, "rus");

    do {
        print_menu();

      

        variant = get_variant(7); 
        switch (variant) {
        case 1:
            char text[255];
            cout << "Проверка палиндрома\n";
            cout << "Введите текст\n";
            std::cin.ignore();
            cin.getline(text, 255);
            if (Palindrom(text) == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;


        case 2:
            char text3[255];
            cout << "Введите текст\n";
            std::cin.ignore();
            cin.getline(text3, 255);
            char t2[255];
            cout << "Введите подстроку\n";
            cin >> t2;

            int* m;
            m = find_substring2(text3, t2);

            break;

        case 3:
            char text4[255];
            cout << "Введите текст\n";
            std::cin.ignore();
            cin.getline(text4, 255);
            int p2;
            cout << "Введите ключ\n";
            cin >> p2;
            encrypt(text4, p2);
            break;

        case 4:
            quotation_marks();
            break;
        }
        if (variant != 6)
            system("pause");
    } while (variant != 6);
}