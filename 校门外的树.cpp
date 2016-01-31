#include <iostream>
using namespace std;
int main() {
	int all = 0;
	int row = 0;
	int counts = 1;
	cin >> all >> row; //输入第一部分数据
	int arr[200] = {0}; //树 部分的数组
	for (int i = 0; i < row; i++) { //输入第二部分
		cin >> arr[2 * i] >> arr[2 * i + 1];
		if (arr[2 * i] > arr[2 * i + 1]) {//若第二个数字小于第一个 调换
			int tmp = arr[2 * i];
			arr[2 * i] = arr[2 * i + 1];
			arr[2 * i + 1] = arr[2 * i];
		}
	}
	int tree[200] = {0}; //定义计算过一次的数组
	int con = row;
	int row2 = row;
	for (int j = 0; j < con; j++) { //通过对arr当前组范围是否在tree组中，若在 则忽略。若范围更大，则扩大tree当前组的范围。若不在当前tree组里 则放到下一组里。
		tree[2 * j] = arr[2 * j], tree[2 * j + 1] = arr[2 * j + 1]; 
		arr[2 * j] = 0, arr[2 * j + 1] = 0; //将第一组arr的数据放到tree中 并将arr清零
		while (row2 > 0) { //循环次数
			for (int i = j; i < con; i++) { // 进行判断
				bool cond = true; //是否在组内的判断
				if (arr[2 * i] <= tree[2 * j] && arr[2 * i + 1] >= tree[2 * j + 1]) {
					tree[2 * j] = arr[2 * i];
					tree[2 * j + 1] = arr[2 * i + 1];
					arr[2 * i] = 0;
					arr[2 * i + 1] = 0; //处理过就清零
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
			}
			row2--;
		}
		row2 = row; //循环清零
	}
//开始计算和
	int sum = 0;
	for (int i = 0; i < con; i++) { //arr中剩余的项目
		if (arr[2 * i] == 0) continue;
		sum += (arr[2 * i + 1] - arr[2 * i] + 1);
		
	}
	for (int j = 0; j < con; j++) { // tree中的
		if (tree[2 * j] == 0) continue;
		sum += (tree[2 * j + 1] - tree[2 * j] + 1);
	}
//打印 和
	cout << (all + 1 - sum);
	return 0;
}