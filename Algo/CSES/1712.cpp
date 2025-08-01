#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

const int mod = 1e9 + 7;

int qpow (unsigned long long a, int b, int p) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

int main () {
    AC
    int n; cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        int pow = qpow(b, c, mod-1);
        cout << qpow(a, pow, mod) << '\n';
    }
    return 0;
}