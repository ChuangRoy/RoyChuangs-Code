#include <bits/stdc++.h>

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int qpow (int a, int b, int p)
{
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

signed main ()
{
    AC
    int n, m;
    cin >> n >> m;
    int a = 1;
    m = min(m, n - m);
    for (int i = n; i > n - m; i--) {
        a = (a * i) % mod;
    }
    for (int i = 1; i <= m; i++) {
        int mi = qpow(i, mod - 2, mod);
        a = (a * mi) % mod;
    }
    cout << a << '\n';
    return 0;
}