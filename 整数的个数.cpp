#include <iostream>
using namespace std;
int main() {
	int row;
	cin >> row;
	int number[row];
	for (int i = 0; i < row; ++i)
	{
		cin >> number[i];
	}
	int number1 = 0, number5 = 0, number10 = 0;
	for (int i = 0; i < row; ++i)
	{
		if (number[i] == 1)
		{
			number1++;
		}
		else if (number[i] == 5)
		{
			number5++;
		}
		else if (number[i] == 10)
		{
			number10++;
		}
	}
	cout << number1 <<endl;
	cout << number5 <<endl;
	cout << number10 <<endl;
	return 0;
}