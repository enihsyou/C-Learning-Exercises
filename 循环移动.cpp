#include <iostream>
using namespace std;
int main() {
	int number = 0;
	int offset = 0;
	cin >> number >> offset;
	int num[100] = {0};
	for (int i = offset; i < offset + number; i++) {
		cin >> num[i];
	}
	for (int i = number; i < number + offset; i++) {
		num[i - number] = num[i];
		num[i] = 0;
	}
	for (int i = 0; i < number; i++) {
		cout << num[i]<<' ';
	}
	// cout << '\b';
	return 0;
}