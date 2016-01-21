#include <iostream>
using namespace std;
int main() {
	int g0;
	cin >> g0;

	int t1 = g0 / 100;
	int g1 = g0 % 100;

	int t2 = g1 / 50;
	int g2 = g1 % 50;

	int t3 = g2 / 20;
	int g3 = g2 % 20;

	int t4 = g3 / 10;
	int g4 = g3 % 10;

	int t5 = g4 / 5;
	int g5 = g4 % 5;

	int t6 = g5 / 1;
	int g6 = g5 % 1;

	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
	cout << t4 << endl;
	cout << t5 << endl;
	cout << t6 << endl;
	return 0;
}