#include <iostream>
using namespace std;
int main() {
	int m, n, result = 0;
	cin >> m >> n;
	while (m <= n) {
		if (m % 2 == 1) {
			result += m;
		}
		else if (m++ < n) {
			result += m;
		}
		m += 2;
	}
	cout << result;
	return 0;
}