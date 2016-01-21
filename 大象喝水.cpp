#include <iostream>
using namespace std;
int main() {
	int need = 20 * 1000;
	int depth;
	int r;
	double Pi = 3.14159;

	cin >> depth >> r;

	double v = Pi * r * r * depth;

	int result = need / v;
	cout << result + 1;
	return 0;
}