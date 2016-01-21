#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n >= 95)
		cout << 1;
	else if (n >= 90)
		cout << 2;
	else if (n >= 85)
		cout << 3;
	else if (n >= 80)
		cout << 4;
	else if (n >= 70)
		cout << 5;
	else if (n >= 60)
		cout << 6;
	else
		cout << 7;
	return 0;
}