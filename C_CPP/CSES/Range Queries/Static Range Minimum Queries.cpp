#include <bits/stdc++.h>
using namespace std;

int lg(int x) {
    return 31 - __builtin_clz(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<vector<int>> st(__lg(n) + 1, vector<int>(n)); // n * log n
    for (int i = 0; i < n; i++) st[0][i] = x[i]; // len = 1 時最小值等於自己
    for (int i = 1; i <= lg(n); i++) {
        int len = 1 << (i - 1); // 若當前處理長度 4 的區間，需要兩個長度 2 合併
        for (int j = 0; j + len < n; j++) {
        	st[i][j] = min(st[i - 1][j], st[i - 1][j + len]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int k = lg(r - l + 1); // 二的次方數
        cout << min(st[k][l], st[k][r - (1 << k) + 1]) << '\n';
    }
    
    return 0;
}