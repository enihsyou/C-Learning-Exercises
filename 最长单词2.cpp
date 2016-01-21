#include <iostream>
using namespace std;
int main() {
	int long_i1, long_i2 = {0};
	char input_line[500] = {0};
	char longstring[50] = {0};
	char longstring_temp[50] = {0};
	int long_now = 0;
	int long_even = 0;
	int tempi = -1;
	cin.getline(input_line, 500);
	for (int i = 0; i < 500; i++) {
		if (input_line[i] == ' ') {
			long_now = i - tempi - 1;
			if (long_now > long_even) {
				long_i1 = tempi + 1;
				long_i2 = i;
				long_even = long_now;
			}
			tempi = i;
		}
		if (input_line[i] == '.') {
			long_now = i - tempi - 1;
			if (long_now > long_even) {
				long_i1 = tempi + 1;
				long_i2 = i;
				long_even = long_now;
			}
			tempi = i;
			break;
		}
	}
	for (long_i1; long_i1 < long_i2; long_i1++) {
		cout << input_line[long_i1];
	}
	return 0;
}