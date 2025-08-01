#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// a ^ b
long long expo (long long a, long long b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    long long half_expo;
    half_expo = expo(a, b / 2);
    if (b % 2) {
        return (((half_expo * half_expo) % mod) * a) % mod;
    } else {
        return (half_expo * half_expo) % mod;
    }
}

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b;
        cout << expo(a, b) << endl;
    }
    return 0;
}