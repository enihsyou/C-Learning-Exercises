#include <iostream>
using namespace std;
int main() {
	int aeiou[5] = {0};
	char s[80];
	cin.getline(s, 80);
	
	for (int i = 0; i < 80; i++) {
		switch (s[i]) {
			case 'a':aeiou[0]++; break;
			case 'e':aeiou[1]++; break;
			case 'i':aeiou[2]++; break;
			case 'o':aeiou[3]++; break;
			case 'u':aeiou[4]++; break;
			//case 'A':aeiou[0]++; break;
			//case 'E':aeiou[1]++; break;
			//case 'I':aeiou[2]++; break;
			//case 'O':aeiou[3]++; break;
			//case 'U':aeiou[4]++; break;
			default: continue;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << aeiou[i]<<' ';
	}
	// cout << '\b';
	return 0;
}