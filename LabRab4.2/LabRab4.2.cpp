#include <iostream>
#include <string>
#include <fstream>
using namespace std;






string file_format(const string file_path_full)
{
    int dot = file_path_full.find_last_of(".");
    if (dot != string::npos)
    {
        return file_path_full.substr(dot + 1, file_path_full.size() - dot);
    }
}
string file_name(const string file_path_full)
{
    int slash = file_path_full.find_last_of("\\");
    int dot = file_path_full.find_last_of(".");
    if ((slash != string::npos) && (dot != string::npos))
    {
        return file_path_full.substr(slash + 1, dot - slash - 1);
    }
}
string file_path(const string file_path_full)
{
    int slash = file_path_full.find_last_of("\\");
    if (slash != string::npos)
    {
        return file_path_full.substr(0, slash);
    }
}
char file_disk(const string file_path_full)
{
    int dot2 = file_path_full.find_last_of(":");
    if (dot2 != string::npos)
    {
        return file_path_full.substr(0, file_path_full.size() - dot2)[0];
    }
}
bool file_rename(string* file_path_full) 
{
    string name;
    cout << "Новое имя:  ";
    cin >> name;
    char slash = file_path_full->find_last_of("\\");
    int dot = file_path_full->find_last_of(".");
    if ((slash != string::npos) && (dot != string::npos))
    {
        file_path_full->replace(slash + 1, file_path_full->substr(slash, file_path_full->size() - dot).length(), name);
        return true;
    }
    return false;

}

bool file_copy(const string file_path_full)
{
    const static int BUF_SIZE = 4096;

    std::ifstream in(file_path_full, ios_base::in | ios_base::binary); 
    int slash = file_path_full.find_last_of("\\");
    int dot = file_path_full.find_last_of(".");
    string newFilePath;
    string name = file_path_full.substr(slash + 1, dot - slash - 1) + "_copy";
    if ((slash != string::npos) && (dot != string::npos))
    {
        string file_path_full_copy = file_path_full;
        newFilePath = file_path_full_copy.replace(slash + 1, file_path_full.substr(slash + 1, dot - slash - 1).length(), name);
    }
    std::ofstream out(newFilePath, ios_base::out | ios_base::binary);
    char buf[BUF_SIZE];        

    do {

        in.read(&buf[0], BUF_SIZE);      
        out.write(&buf[0], in.gcount());

    } while (in.gcount() > 0);      

    in.close();

    out.close();

    return true;

};
void print_menu() {

    cout << endl;
    cout << "Введите 1 для вывода расширения файла" << endl;
    cout << "Введите 2 для вывода имени файла" << endl;
    cout << "Введите 3 для вывода адресса файла" << endl;
    cout << "Введите 4 для вывода диска, на котором рвсположен файл" << endl;
    cout << "Введите 5, чтобы переименовать файл" << endl;
    cout << "Введите 6, чтобы создать копию файла" << endl;
    cout << "Введите 7 для завершения программы" << endl;
    cout << ">";
};

int get_variant(int count) {
    int variant;
    int s;
    cin >> s; 

    
    while (s < 1 || s > count) {
        printf("Неверный ввод. Пробовать снова: "); 
        cin >> s; 
    }
    variant = s;
    return variant;
};
int main()
{

    setlocale(0, "rus");
    int variant;
    cout << "Введите полный путь к фалу: ";

    std::string Path;
    std::getline(std::cin, Path);

    string* path = &Path;
    do {
        print_menu();

      

        variant = get_variant(7); 



        switch (variant) {
        case 1:
            cout << "Расширение файла: ";
            cout << file_format(Path) << endl;
            break;

        case 2:
            cout << "Имя файла: ";
            cout << file_name(Path) << endl;
            break;

        case 3:
            cout << "Адресс файла: ";
            cout << file_path(Path) << endl;
            break;

        case 4:
            cout << "Файл расположен на диске: ";
            cout << file_disk(Path) << endl;
            break;

        case 5:
            cout << file_rename(path) << endl;
            cout << "Файл переименован\n";
            break;

        case 6:
            cout << file_copy(Path) << endl;
            cout << "Копия созданна\n";
            break;
        }

        if (variant != 7)
            system("pause"); 
    } while (variant != 7);
}