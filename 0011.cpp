#include <iostream>
using namespace std;

int main() {
    int max = 0;
    int min = 100;
    double avg = 0;
    int n = 0;
    int inp = 0;
    while (true) {
        cin >> inp;
        if (inp == -999) break;
        if (inp > 100 || inp < 0) continue;
        if (inp > max) max = inp;
        if (inp < min) min = inp;
        avg = (avg * n + inp) / (n + 1);
        n++;
    }
    cout << "最大值:" << max << "\n最小值:" << min << "\n成绩个数:" << n << "\n平均值:" << avg;
    system("pause");
    return 0;
}
