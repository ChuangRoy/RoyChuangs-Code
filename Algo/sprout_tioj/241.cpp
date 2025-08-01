#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long int lli;

int qpow (unsigned long long a, int b, int p) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

const lli hash_mul = 257, hash_mod = 998244353;
const int inf = 1e9;

lli RK_hash (string s) {
    lli hash = 0;
    for (char c : s) {
        hash *= hash_mul;
        hash += c;
        if (hash >= hash_mod) hash %= hash_mod;
    }
    return hash;
}

void solve () {
    string S;
    cin >> S;
    int N = SZ(S);
    lli hash_s = RK_hash(S);
    for (int szSubStr = 1; szSubStr < N; szSubStr++) {
        if (N % szSubStr) continue;
        lli hash_substr = RK_hash(S.substr(0, szSubStr));
        int len = 0;
        lli res = 0;
        while (len < N) {
            len += szSubStr;
            res *= qpow(hash_mul, szSubStr, hash_mod);
            res += hash_substr;
            if (res >= hash_mod) res %= hash_mod;
        }
        if (res == hash_s) {
            cout << szSubStr << '\n';
            return;
        }
    }
    cout << N << '\n';
}

int main () {
    fastio;
    solve();
    return 0;
}