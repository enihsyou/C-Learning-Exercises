#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int score[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> score[i];
	}

	int tmpMax = score[0];
	for (int i = 0; i < n; ++i)
	{
		if (score[i] > tmpMax)
		{
			tmpMax = score[i];
		}
	}
	cout << tmpMax;
	return 0;
}