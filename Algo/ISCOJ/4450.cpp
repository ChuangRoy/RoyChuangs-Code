// ISCOJ 4450 https://iscoj.fg.tp.edu.tw/problems/4450

#include <bits/stdc++.h>
using namespace std;

int a[5000006];

int main () {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int si;
        cin >> si;
        a[si] = i;
    }
    long long c = a[1];
    for (int i = 2; i <= n; i++) {
        c += abs(a[i] - a[i-1]);
    }
    cout << c << endl;
}