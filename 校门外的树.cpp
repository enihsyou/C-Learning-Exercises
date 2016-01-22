#include <iostream>
using namespace std;
int main() {
	int all = 0;
	int row = 0;
	int counts = 1;
	cin >> all >> row; //Input the number of trees and how many rows datum
	int arr[200] = {0};
	for (int i = 0; i < row; i++) { //input datum
		cin >> arr[2 * i] >> arr[2 * i + 1];
		if (arr[2 * i] > arr[2 * i + 1]) {//change the array for which the second less than the first
			int tmp = arr[2 * i];
			arr[2 * i] = arr[2 * i + 1];
			arr[2 * i + 1] = arr[2 * i];
		}
	}
	int tree[200] = {0};
	int con = row;
	int row2 = row;
//每一次大循环从arr放下去一组数据到tree里，在小循环内每次检查当前数据与tree相应位置的范围大小。成功检测的组清零。
	for (int j = 0; j < con; j++) {
		tree[2 * j] = arr[2 * j], tree[2 * j + 1] = arr[2 * j + 1];
		arr[2 * j] = 0, arr[2 * j + 1] = 0;
		while (row2 > 0) {
			for (int i = j; i < con; i++) {
				bool cond = true;
				if (arr[2 * i] <= tree[2 * j] && arr[2 * i + 1] >= tree[2 * j + 1]) {
					tree[2 * j] = arr[2 * i];
					tree[2 * j + 1] = arr[2 * i + 1];
					arr[2 * i] = 0;
					arr[2 * i + 1] = 0;
					cond = false;
				}
				if (arr[2 * i] <= tree[2 * j] && arr[2 * i + 1] >= tree[2 * j] && arr[2 * i + 1] <= tree[2 * j + 1]) {
					tree[2 * j] = arr[2 * i];
					arr[2 * i] = 0;
					arr[2 * i + 1] = 0;
					cond = false;
				}
				if (arr[2 * i] >= tree[2 * j] && arr[2 * i] <= tree[2 * j + 1] && arr[2 * i + 1] >= tree[2 * j + 1]) {
					tree[2 * j + 1] = arr[2 * i + 1];
					arr[2 * i] = 0;
					arr[2 * i + 1] = 0;
					cond = false;
				}
				if (arr[2 * i] >= tree[2 * j] && arr[2 * i + 1] <= tree[2 * j + 1]) {
					arr[2 * i] = 0;
					arr[2 * i + 1] = 0;
					continue;
					cond = false;
				}
				//if (cond) {
				//	tree[2 * (i - 1)] = arr[2 * i];
				//	tree[2 * (i - 1) + 1] = arr[2 * i + 1];
				//	counts++;
				//}
			}
			row2--;
		}
		row2 = row;
	}
// compute the sum
	int sum = 0;
	for (int i = 0; i < con; i++) {
		if (arr[2 * i] == 0) continue;
		sum += (arr[2 * i + 1] - arr[2 * i] + 1);
		
	}
	for (int j = 0; j < con; j++) {
		if (tree[2 * j] == 0) continue;
		sum += (tree[2 * j + 1] - tree[2 * j] + 1);
	}
//print the sum
	cout << (all + 1 - sum);
	return 0;
}