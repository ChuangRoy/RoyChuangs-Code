#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

void solve () {
    ll n; int k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++)
        cin >> primes[i];
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        int cnt = 0;
        ll prod = 1;
        for (int i = 0; i < k; i++) {
            if (!(mask & (1 << i))) continue;
            cnt++;
            if (primes[i] >= n / prod + 1) {
                prod = n + 1;
                break;
            }
            prod *= primes[i];
        }
        if (cnt % 2)
            ans += n / prod;
        else
            ans -= n / prod;
    }
    cout << ans << '\n';
}

int main () {
    AC
    solve();
    return 0;
}