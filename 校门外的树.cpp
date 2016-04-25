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
	int tree[200] = {0};

	int now_min = arr[0];
	int now_min_i = -1;
	int tree_index = 0;

	for (int j = 0; j < row; j++) {
		for (int i = 0; i < row; i++) {
			if (arr[2 * i] <= now_min) {
				now_min = arr[2 * i];
				now_min_i = i;
			}
		} //找到最小的数和他的index
		tree[tree_index] = arr[2 * now_min_i]; tree[tree_index + 1] = arr[2 * now_min_i + 1];
		arr[2 * now_min_i] = 0; arr[2 * now_min_i + 1] = 0;
		tree_index+=2;
		for (int k = 0; k < row; k++) {
			if (arr[2 * k] != 0) {
				now_min = arr[0]; break;
			}
		}
	}

	//			if (arr[2 * i] <= tree[2 * j] && arr[2 * i + 1] >= tree[2 * j + 1]) {
	//				tree[2 * j] = arr[2 * i];
	//				tree[2 * j + 1] = arr[2 * i + 1];
	//				arr[2 * i] = 0;
	//				arr[2 * i + 1] = 0;
	//				cond = false;
	//			}
	//			if (arr[2 * i] <= tree[2 * j] && arr[2 * i + 1] >= tree[2 * j] && arr[2 * i + 1] <= tree[2 * j + 1]) {
	//				tree[2 * j] = arr[2 * i];
	//				arr[2 * i] = 0;
	//				arr[2 * i + 1] = 0;
	//				cond = false;
	//			}
	//			if (arr[2 * i] >= tree[2 * j] && arr[2 * i] <= tree[2 * j + 1] && arr[2 * i + 1] >= tree[2 * j + 1]) {
	//				tree[2 * j + 1] = arr[2 * i + 1];
	//				arr[2 * i] = 0;
	//				arr[2 * i + 1] = 0;
	//				cond = false;
	//			}
	//			if (arr[2 * i] >= tree[2 * j] && arr[2 * i + 1] <= tree[2 * j + 1]) {
	//				arr[2 * i] = 0;
	//				arr[2 * i + 1] = 0;
	//				continue;
	//				cond = false;
	//			}
	//		}
	//		row2--;
	//	}
	//	row2 = row;
	//}

	//int sum = 0;
	//for (int i = 0; i < con; i++) {
	//	if (arr[2 * i] == 0) continue;
	//	sum += (arr[2 * i + 1] - arr[2 * i] + 1);
	//	
	//}
	//for (int j = 0; j < con; j++) {
	//	if (tree[2 * j] == 0) continue;
	//	sum += (tree[2 * j + 1] - tree[2 * j] + 1);
	//}

	//cout << (all + 1 - sum);
	return 0;
}


//500 3 130 150 180 320 100 200