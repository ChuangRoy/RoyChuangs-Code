#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

int main () {
    AC
    ll a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    ll n; cin >> n;
    ll ans = -LLONG_MAX;
    for (ll x1 = n; x1 >= 0; x1--) {
        ll x2 = n - x1;
        ll y = (a1 * x1 + b1) * x1 + c1
              +(a2 * x2 + b2) * x2 + c2;
        ans = max(y, ans);
    }
    cout << ans << '\n';
    return 0;
}