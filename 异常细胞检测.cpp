#include <iostream>
using namespace std;
int main() {
	int n = 100;
	cin >> n;
	int matrix[100][100] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int counts = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (matrix[i][j] <= matrix[i + 1][j] - 50)
				if (matrix[i][j] <= matrix[i - 1][j] - 50)
					if (matrix[i][j] <= matrix[i][j + 1] - 50)
						if (matrix[i][j] <= matrix[i][j - 1] - 50)
							counts++;
		}
	}
	cout << counts;
return 0;
}