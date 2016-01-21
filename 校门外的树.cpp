#include <iostream>
using namespace std;
int main() {
	int all = 0;
	int row = 0;
	int counts = 1;
	cin >> all >> row;
	int arr[200] = {0};
	for (int i = 0; i < row; i++) {
		cin >> arr[2 * i] >> arr[2 * i + 1];
		if (arr[2 * i] > arr[2 * i + 1]) {
			int tmp = arr[2 * i];
			arr[2 * i] = arr[2 * i + 1];
			arr[2 * i + 1] = arr[2 * i];
		}
	}
	int tree[200] = {arr[0],arr[1]};
	for (int i = 1; i < row; i++) {
		bool cond = true;
		if (arr[2 * i] <= tree[0] && arr[2 * i + 1] >= tree[1]) {
			tree[0] = arr[2 * i];
			tree[1] = arr[2 * i + 1];
			cond = false;
		}
		if (arr[2 * i] <= tree[0] && arr[2 * i + 1] >= tree[0] && arr[2 * i + 1] <= tree[1]) {
			tree[0] = arr[2 * i];
			cond = false;
		}
		if (arr[2 * i] >= tree[0] && arr[2 * i] <= tree[1] && arr[2 * i + 1] >= tree[1]) {
			tree[1] = arr[2 * i + 1];
			cond = false;
		}
		if (arr[2 * i] >= tree[0] && arr[2 * i + 1] <= tree[1]) {
			continue;
			cond = false;
		}
		if (cond) {
			tree[2 * (i - 1)] = arr[2 * i];
			tree[2 * (i - 1) + 1] = arr[2 * i + 1];
			counts++;
		}
	}
	int sum = 0;
	for (int i = 0; i < counts; i++) {
		sum += (tree[2 * i + 1] - tree[2 * i] + 1);
	}
	cout << (all - sum + 1);
	return 0;
}