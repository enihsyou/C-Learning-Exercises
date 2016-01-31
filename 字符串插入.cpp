#include <iostream>
using namespace std;
int main() {
	char str[15] = {}, substr[4] = {}; //创建并初始化
	while (cin >> str >> substr) { //输入
		int strmax = 0;
		for (int i = 0; i < 10; i++) { //找到第一个最大的字符的下标
			if (str[i] > str[strmax]) strmax = i;
		}
		for (int i = 0; i < strmax + 1; i++) { //输出最大的及其之前的字符
			cout << str[i];
		}
			cout << substr; //输出substr
			for (int i = strmax + 1; i < 11; i++) { //输出剩余的
				if (str[i] != '\0') cout << str[i]; //定点结束
		}
			cout << endl;
	}
	return 0;
}