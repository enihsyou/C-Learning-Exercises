#include <iostream>
using namespace std;
int main() {
	int list[6];
	for (int i = 0; i < 6; ++i)
	{
		cin >> list[i];
	}
	int odd = 1;
	int even = 100;
	for (int i = 0; i < 6; ++i)
	{
		if (list[i] % 2 == 0)
		{
			if (list[i] < even)
			{
				even = list[i];
			}
		}
		else {
			if (list[i] > odd)
			{
				odd = list[i];
			}
		}
	}
	int abs;
	int min = odd - even;
	if (min < 0)
	{
		min = -min;
	}
	cout <<  min;
	return 0;
}