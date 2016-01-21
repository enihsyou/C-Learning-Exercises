#include <iostream>
using namespace std;
int main() {
	char a[80] = {0};
	char b[80] = {0};

	cin.getline(a, 80);
	cin.getline(b, 80);

	int res = 0;
	for (int i = 0; i < 80; i++) {
		if (64 < a[i] && a[i] < 91) a[i] += 32;
		if (64 < b[i] && b[i] < 91) b[i] += 32;
		if (a[i] == b[i]) continue;
		else if (a[i] > b[i]) {
			res = 1; break;
		}
		else if (a[i] < b[i]) {
			res = 2; break;
		}
	}
	switch (res) {
		case 0: cout << '='; break;
		case 1: cout << '>'; break;
		case 2: cout << '<'; break;
	}
	return 0;
}