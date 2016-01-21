#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	int K;
	int price = 200;
	while (cin >> N >> K) {
		float m = 100 + K;
		float k = m / 100;
		for (int i = 1; i < 22; i++) {
			float po = price * pow(k, i - 1);
			float gete = i * N;
			if (gete >= po) {
				if (i < 21) {
					cout << i << endl;
					break;
				}
			}
			else if (i >= 21) {
				cout << "Impossible" << endl;
			}
			}
		}
	return 0;
}