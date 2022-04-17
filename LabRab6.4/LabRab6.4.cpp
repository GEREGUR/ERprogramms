#include <set>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	set <int> akk; 
	akk.insert(0); 
	while (true)
	{
		int id;
		cout << "Введите ID пользователя\n";
		cin >> id;
		if (akk.find(id) == akk.end()) 
		{
			akk.insert(id);
		}
		else
		{
			cout << "Повторное использование аккаунта с ID " << id << endl;
			break;
		}
	}






}
