#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int number;
	cin >> number;
	int grade[100];
	double g1 = 0;
	double g2 = 0;
	double g3 = 0;
	double g4 = 0;
	for (int i = 0; i < number; i++) {
		cin >> grade[i];
	}
	for (int i = 0; i < number; i++) {
		if (grade[i] > 60) {
			g4++;
		}
		else if (grade[i] >= 36) {
			g3++;
		}
		else if (grade[i] >= 19) {
			g2++;
		}
		else {
			g1++;
		}
	}
	g1 = g1 / number;
	g2 = g2 / number;
	g3 = g3 / number;
	g4 = g4 / number;
	cout << "1-18: " << fixed;
	cout << setprecision(2) << g1* 100 << "%" << endl;
	cout << "19-35: " << g2 * 100 << "%" << endl;
	cout << "36-60: " << g3 * 100 << "%" << endl;
	cout << "60-: " << g4 * 100 << "%" << endl;
	return 0;
}