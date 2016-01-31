#include <iostream>
using namespace std;
int main() {
	int in;
	while(cin >> in) {
	bool con1 = true, con2 = true, con3 = true;
	if (in % 3 == 0) {
		cout << '3' << ' ';
	}else con1 = false;
	if (in % 5 == 0) {			
		cout << '5' << ' ';
	}else con2 = false;
	if (in % 7 == 0) {
		cout << '7';
	}else con3 = false;
	if (not(con1 or con2 or con3)) cout << 'n';
	cout << endl;
}
	return 0;
}