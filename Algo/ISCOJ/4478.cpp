#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin >> q;
    int n;
    vector<long long> a(1e6+10);
    a[0] = 1;
    for (long long i = 1; i < 1e6+10; i++) {
        a[i] = (a[i-1] * i) % mod;
    }
    while (q--) {
        cin >> n;
        cout << a[n-1] << endl;
    }
    return 0;
}