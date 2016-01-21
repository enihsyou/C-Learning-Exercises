#include <iostream>
using namespace std;
int main() {
loop:
	int n = 0, now = 0;
	int max_now = 0;
	double mid_num = 0;
	int num[15000] = {0};
	cin >> n;
	if (n != 0) {
		while (now < n) {
			int inp = 0;
			cin >> inp;
			num[now] = inp;
			if (inp > max_now) max_now = inp;
			now++;
		}
		if (n % 2 == 1) {
			int mid = n / 2;
			int tmp_max = 0;
			for (int j = 0; j < mid; j++) {
				int index = 0;
				for (int i = 0; i < n; i++) {
					if (num[i] >= tmp_max) {
						tmp_max = num[i];
						index = i;
					}
				}
				num[index] = 0;
				tmp_max = 0;
			}
			for (int j = 0; j < 1; j++) {
				int index = 0;
				for (int i = 0; i < n; i++) {
					if (num[i] >= tmp_max) {
						tmp_max = num[i];
						index = i;
					}
				}
				mid_num = num[index];
			}
		}
		else {
			int mid = n / 2 - 1;
			int tmp_max = 0;
			int mid_tmp[2] = {0};
			for (int j = 0; j < mid; j++) {
				int index = 0;
				for (int i = 0; i < n; i++) {
					if (num[i] >= tmp_max) {
						tmp_max = num[i];
						index = i;
					}
				}
				num[index] = 0;
				tmp_max = 0;
			}
			for (int j = 0; j < 2; j++) {
				int index = 0;
				for (int i = 0; i < n; i++) {
					if (num[i] >= tmp_max) {
						tmp_max = num[i];
						index = i;
					}
				}
				mid_tmp[j] = num[index];
				num[index] = 0;
				tmp_max = 0;
			}
			mid_num = (mid_tmp[0] + mid_tmp[1]) / 2;
		}
		cout << mid_num << endl;
		goto loop;
	}
	else if (n == 0) {
		goto ending;
	}
ending:
	return 0;
}