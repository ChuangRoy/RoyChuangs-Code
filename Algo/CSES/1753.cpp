#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long int lli;

int qpow(unsigned long long a, int b, int p) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

const lli hash_mod = 998244353;
const lli hash_mul = 257;

lli RK_hash(string s) {
    lli hash = 0;
    lli prefix_mul = 1;
    for (char c : s) {
        hash += c * prefix_mul;
        prefix_mul *= hash_mul;
        prefix_mul %= hash_mod;
        if (hash >= hash_mod) hash %= hash_mod;
    }
    return hash;
}

void solve() {
    string S, pattern;
    cin >> S >> pattern;
    int N = SZ(S);
    int M = SZ(pattern);
    lli hash_window = 0;
    lli hash_pattern = RK_hash(pattern);
    // cerr << hash_pattern << endl;
    int cnt = 0;
    vector<lli> prefix_hash(N+1);
    prefix_hash[0] = 0;
    lli prefix = 0;
    lli prefix_mul = 1;
    for (int i = 0; i < N; i++) {
        prefix += S[i] * prefix_mul;
        prefix %= hash_mod;
        prefix_hash[i+1] = prefix;
        prefix_mul *= hash_mul;
        prefix_mul %= hash_mod;
        // cerr<<prefix<<'\n';
    }
    // cerr<<"---\n";
    lli mod_inverse = qpow(hash_mul, hash_mod - 2, hash_mod);
    for (int i = M - 1; i < N; i++) {
        lli hash = prefix_hash[i+1] - prefix_hash[i-M+1];
        // cerr<<hash<<'\n';
        if (hash < 0) hash += hash_mod;
        hash *= qpow(mod_inverse, i - M + 1, hash_mod);
        hash %= hash_mod;
        // cerr << hash << endl;
        if (hash == hash_pattern) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}