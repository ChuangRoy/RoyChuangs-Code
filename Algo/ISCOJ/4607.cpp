#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    long long n;
    cin >> n;
    if (n >= 0) {
        if (n & 1) cout << "正奇數\n";
        else cout << "正偶數\n";
    } else {
        if (n & 1) cout << "負奇數\n";
        else cout << "負偶數\n";
    }
}

int main () {
    solve();
    return 0;
}