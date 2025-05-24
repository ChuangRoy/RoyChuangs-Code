#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long a, b;
    cin >> a >> b;
    cout << a + b << ' ';
    cout << a - b << ' ';
    cout << a * b << ' ';
    cout << a / b << '\n';
}

int main () {
    solve();
    return 0;
}