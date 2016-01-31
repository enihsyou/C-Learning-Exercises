#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	double a[100][2];
	double b[100][2];
	for (int i=0;i<n;i++){
		cin >> a[i][0] >> a[i][1];
	}
	int count = 0;
	for (int i = 0;i<n;i++){
		for (int j =i;j<n;j++){
			b[count][0] = a[i][0] - a[j][0];
			b[count][1] = a[i][1] - a[j][1];
			count ++;
		}
	}
	double c[100];
	for (int i=0;i < count;i++){
		c[i] = sqrt((b[i][0])*(b[i][0]) + (b[i][1]) * (b[i][1]));
	}
	double max = c[0];
	for (int i =1;i < count;i++){
		if (c[i] > max) {
			max = c[i];
		}
	}
	cout << fixed << setprecision(4) << max << endl;
	return 0;
}