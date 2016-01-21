#include <iostream>
using namespace std;

int main() {
	int n; //apple
	int x; //need time
	int y; //elapsed
	int b;
	cin >> n >> x >> y;
	int a = y / x;
	if (y % x == 0) {
		b = n - a;
	}
	else {
		b = n - a - 1;
	}

	if (b >= 0) {
		cout << b;
	}
	else {cout << 0;}
	return 0;
}