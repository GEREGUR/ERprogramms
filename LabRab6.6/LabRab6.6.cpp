#include <iostream>
#include <map>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	string word; 
	cout << "Введите текст: ";
	int c_word = 0; 
	ofstream in_text;
	ifstream out_text;
	map<string, int> text; 
	map<string, int>::iterator it; 
	while (cin.peek() != '\n') 
	{

		cin >> word; 

		
		
		in_text.open("data.txt", ios::app);
		in_text << word << endl;
		in_text.close(); 
		out_text.open("data.txt", ios::in); 
		for (int i = c_word - 1; i > 0; i--) 
		{
			string buff;
			out_text >> buff; 
		}
		string out;
		out_text >> out; 
		c_word++;
		text[out]++; 
		out_text.close(); 
	}
	cout << endl;
	for (it = text.begin(); it != text.end(); it++)
	{
		int proc = 0;
		proc = ((it->second) / (c_word * 1.0)) * 100; 
		cout << it->first << " - " << proc << "%" << endl;
	}
	system("pause");
	return 0;
}