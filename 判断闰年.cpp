#include <iostream>
using namespace std;
int main() {
	int year;
	bool con = false;
	cin >> year;
	if (year % 4 == 0) {
		con = true;
		if (year % 100 == 0 and year % 400 != 0) {
			con = false;
		}
		if (year % 3200 == 0) {
			con = false;
		}
	}
	if (con) {
		cout << 'Y' << endl;
	}
	else {
		cout << 'N' << endl;
	}
	return 0;
}