#include <iostream>
using namespace std;
int main() {
	int r;
	cin >> r;
	double tb = 27;
	double vb = 3.0;
	double tw = 23;
	double vw = 1.2;
	for (int i = 0; i < r; i++)
	{
		double ti;
		cin >> ti;
		if (tb + ti / vb + tw> ti / vw)
		{
			cout << "Walk" << endl;
		}
		else if (tb + ti / vb + tw < ti / vw)
		{
			cout << "Bike" << endl;
		}
		else
		{
			cout << "All" << endl;
		}
	}
	return 0;
}