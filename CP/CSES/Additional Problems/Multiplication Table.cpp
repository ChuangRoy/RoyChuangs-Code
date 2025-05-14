#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);

using namespace std;
typedef long long ll;

void solve () {
    ll n;
    cin >> n;
    ll l = 1, r = n * n;
    ll target = (n * n + 1) >> 1; 
    while (l < r) {
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        if (cnt >= target)
        	r = mid;
        else
        	l = mid + 1;
    }
    cout << l << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
