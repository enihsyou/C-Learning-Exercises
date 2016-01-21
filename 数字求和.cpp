#include <iostream>
using namespace std;
int main() {
	int ini;
	cin >> ini;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int v;
		cin >> v;
		if (v < ini)
		{
			sum += v;
		}
	}
	cout << sum;
	return 0;
}