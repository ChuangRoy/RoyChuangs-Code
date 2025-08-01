#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

long long qpow (unsigned long long a, unsigned long long b, int p) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

long long geoSeqSum (ll r, ll n) { // r ^ 0 + r ^ 1 + ... + r ^ n
    long long mi = qpow(r-1, mod-2, mod);
    long long s = qpow(r, n+1, mod) - 1;
    return (s * mi) % mod;
}

int main () {
    AC
    int n; cin >> n;
    ll sum = 1, cnt = 1, prod = 1;
    ll cnt_MOD_1 = 1; // cnt mod (m - 1)
    vector<ll> x(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cnt = cnt * (k[i]+1);
        cnt %= mod;
        sum = sum * geoSeqSum(x[i], k[i]);
        sum %= mod;
        prod = qpow(prod, k[i]+1, mod) * qpow(
                    qpow(x[i], k[i]*(k[i]+1)>>1, mod),
                        cnt_MOD_1, mod);
        // prev prod * ( x[i]^(0+1+..+k[i]) ) ^ divisor cnt
        prod %= mod;
        cnt_MOD_1 = cnt_MOD_1 * (k[i]+1);
        cnt_MOD_1 %= (mod - 1);
    }
    cout << cnt << ' ' << sum << ' ' << prod << '\n';
    return 0;
}