#include <iostream>
using namespace std;
int main() {
	int a,b;
	char c;
	cin >> a>>b>>c;
	switch (c){
		case '+': cout << (a+b)<<endl;break;
		case '-': cout << (a-b)<<endl;break;
		case '*': cout << (a * b)<<endl;break;
		case '/': {
			if (b != 0) cout << (a / b)<<endl;
			else cout <<"Divided by zero!"<<endl;break;}
		default:cout << "Invalid operator!"<<endl;
	}
	return 0;
}