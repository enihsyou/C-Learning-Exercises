#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;
	int hundred = input / 100;
	int dec = input % 100 / 10;
	int unit = input % 100 % 10;
	cout << hundred << endl << dec << endl << unit;
	return 0;
}