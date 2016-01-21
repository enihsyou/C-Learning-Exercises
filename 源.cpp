#include <iostream>
using namespace std;
int Exchg1(int &x, int &y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
	cout << x << y << tmp << endl;
	return 0;
}
int main() {
	int a = 4; int b = 5;
	Exchg1(a, b);
	cout << a << b;
}


