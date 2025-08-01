#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unsigned long long qpow (unsigned long long a, int b, unsigned long long k) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a);
        if (res > k * 1e9) return res;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve () {
    int n, m;
    cin >> n >> m;
    // (r^(n+1)-1) / (r - 1)
    if (n == 1) {
        cout << m+1 << '\n';
        return;
    }
    unsigned long long res = (qpow(n, m+1, n-1) - 1) / (n-1);
    if (res > 1e9)
        cout << "inf\n";
    else
        cout << res << '\n';
}

int main () {
    AC
    solve();
    return 0;
}