#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n;
	cin >> k;
	int count = 0;
	int max = 0;
	int xmax = 0;
	int tmax = 0;
	int mlist[100];
	mlist[0] = max;
	for (int i = 0; i < n; i++) {
		cin >> mlist[i];
	}
	int ti = k;
	for (ti; ti > 0; ti--) {
		for (int i = 0; i < n; i++) {
			if (mlist[i] > tmax) {
				tmax = mlist[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (mlist[i] == tmax) {
				xmax = tmax;
				mlist[i] = 0;
				tmax = 0;
				break;
			}
		}	
	}
	cout << xmax;
	return 0;
}
9
1
3
2
9
7
8
4
6
5
