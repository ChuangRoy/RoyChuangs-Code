#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long qpow (unsigned long long a, int b) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a);
        b >>= 1;
        a = a * a;
    }
    return res;
}

int main () {
    AC
    int q; cin >> q;
    while (q--) {
        long long k; cin >> k;
        long long base = 9;
        int digits = 1;
        while (k - base > 0) {
            k -= base;
            digits++;
            base = 9 * qpow(10, digits - 1) * digits;
        }
        int idx = (k-1) % digits;
        long long num = (k - 1) / digits;
        // cerr << k << ' ' << idx << ' ' << num << endl;
        if (idx == 0) cout << num / qpow(10, digits - 1) % 10 + 1 << '\n';
        else cout << num / qpow(10, digits - 1 - idx) % 10 << '\n';
    }
    return 0;
}