#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	bool cond = false;
	int li[999];
	for (int i = 0; i < n; i++) {
		cin >> li[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (li[i] + li[j] == k && i != j) {
				cout << "yes" << endl;
				//cout << li[i] << " " << li[j] << endl;
				cond = true;
				break;
			}
		}
		if (cond) {
			break;
		}
	}
	if (!cond) {
		cout << "no";
	}
	return 0;
}