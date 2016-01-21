#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int tmp = 0;
	int matrix[5][5] = {0};
	bool cond1 = true;
	bool cond2 = true;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> matrix[i][j];
		}
	}
	int n = 0;
	int m = 0;
	cin >> n >> m;
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		if (n == matrix[i][j]) cond1 = false;
	//		if (m == matrix[i][j]) cond2 = false;
	//	}
	//}
	//if (cond1 || cond2) {
	if (!(n >= 0 && n < 5) || !(m >= 0 && m < 5)) {
		cout << "error" << endl;
		goto stops;
	}
	for (int i = 0; i < 5; i++) {
		tmp = matrix[n][i];
		matrix[n][i] = matrix[m][i];
		matrix[m][i] = tmp;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
stops:
	return 0;
}