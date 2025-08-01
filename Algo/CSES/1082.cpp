#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int TWO_MOD_INVERSE = 500000004;

ll sum (ll a, ll b) {
    ll h = (b - a + 1) % mod;
    ll s = (a + b) % mod;
    return (((h * s) % mod) * TWO_MOD_INVERSE) % mod;
}

void solve () {
    ll n;
    cin >> n;
    ll d = 1;
    ll cnt = 0;
    while (d <= n) {
        ll q = n / d;
        ll end = n / q;
        cnt += sum(d, end) * q;
        if (cnt >= mod)
            cnt %= mod;
        d = end + 1;
    }
    cout << cnt << '\n';
}

int main () {
    AC
    solve();
    return 0;
}