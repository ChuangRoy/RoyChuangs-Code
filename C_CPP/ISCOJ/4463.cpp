// https://iscoj.fg.tp.edu.tw/problems/4463

#include <iostream>
using namespace std;

int main () {
    int n, m, k;
    int max, num;
    int c = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        num = i;
        max = 1;
        while (num > 1) {
            if (num > max)
                max = num;
            if (num % 2 == 0) {
                num /= 2;
            }
            else {
                num = num * 3 + 1;
            }
        }
        if (max % m == k)
            c++;
    }
    cout << c;
    return 0;
}