#include <iostream>
#include <queue>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(2); pq.push(3); pq.push(5);
	int n, x;
	cout << "Введите количесвот числе:";
	cin >> n; 
	cout << endl;
	cout << "Выведено " << n << " чисел, которые имею только простые делители 2, 3, 5\n";
	for (int i = 0; i < n; i++)
	{
		cout << pq.top() << " ";
		x = pq.top();
		pq.push(x * 2);
		pq.push(x * 3);
		pq.push(x * 5);
		pq.pop();
		if (x == pq.top())
		{
			pq.pop();
		}

	}


}
