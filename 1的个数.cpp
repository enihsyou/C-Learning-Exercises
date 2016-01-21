#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int inp1 = 0,num = 0;
		cin >> inp1;
		while(inp1 > 0) {
			num += inp1 % 2;
			inp1 /= 2;
		}
		cout << num << endl;
	}
	return 0;
}