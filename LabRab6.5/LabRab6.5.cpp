#include <iostream>
#include <list>
#include <string>
#include <set>

using namespace std;

struct Student
{
    int group;
    string fio;
    void show()
    {
        cout << group << " " << fio << endl;
    }
};

void printList(list <Student> sts)
{
    for (auto it = sts.begin(); it != sts.end(); it++)
    {
        cout << (*it).group << " " << (*it).fio << endl;
    }
}





void printbygroup(list <Student> sts) 
{
    list <Student> ::iterator it;
    set <int> gru;
    for (it = sts.begin(); it != sts.end(); it++) 
    {

        int gr = (*it).group; 
        list <Student> ::iterator itin; 
        if (gru.find(gr) == gru.end())
        {
            for (itin = sts.begin(); itin != sts.end(); itin++)
            {
                if (gr == (*itin).group)
                {
                    (*itin).show();
                }
            }
            gru.insert(gr);
        }



    }

}

void create_list(list <Student>* sts)
{
    sts->push_back({ 12, "Вася" });
    sts->push_back({ 43, "Коля" });
    sts->push_back({ 13, "Ваня" });
    sts->push_back({ 59, "Антон" });
    sts->push_back({ 13, "Вася" });
    sts->push_back({ 43, "Кирил" });
    sts->push_back({ 12, "Олег" });
    sts->push_back({ 59, "Катя" });
    sts->push_back({ 12, "Таня" });
    sts->push_back({ 12, "Игорь" });
    sts->push_back({ 59, "Женя" });
    sts->push_back({ 13, "Владислав" });

}

int main()
{
    setlocale(LC_ALL, "rus");
    
    list <Student> sts;
   
    create_list(&sts);

  
    printbygroup(sts);
}