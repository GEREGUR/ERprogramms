#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair()
{
	this->age = 0;
	this->family = "";
}
Pair::Pair(string family, int age)
{
	this->age = age;
	this->family = family;
}
void Pair::show()
{
	cout << "Фамилия: " << family << "   " << "Возраст: " << age << endl;
}
bool operator<(const Pair& p1, const Pair& p2)
{
	return p1.age < p2.age;
}
bool operator>(const Pair& p1, const Pair& p2)
{
	return p1.age > p2.age;
}
bool operator<=(const Pair& p1, const Pair& p2)
{
	return p1.age <= p2.age;
}
bool operator>=(const Pair& p1, const Pair& p2)
{
	return p1.age >= p2.age;
}