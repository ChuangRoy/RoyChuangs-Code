#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;

void solve () {
    int n; cin >> n;
    vector dis(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d; cin >> d;
            dis[i][j] = d;
            dis[j][i] = d;
        }
    }
    vector dp((1 << n), vector<ll> (n, inf));
    dp[1][0] = 0;
    for (ll mask = 3; mask < (1 << n); mask += 2) {
        for (int cur = 1; cur < n; cur++) {
            if (! (mask >> cur) & 1) continue;
            ll mask_prev = mask ^ (1 << cur);
            for (int prev = 0; prev < n; prev++) if ( (mask >> prev) & 1) {
                if (cur == prev) continue;
                dp[mask][cur] = min(dp[mask_prev][prev] + dis[cur][prev], dp[mask][cur]);
            }
        }
    }
    ll ans = inf;
    for (int i = 1; i < n; i++) {
        ans = min(dp[(1 << n) - 1][i] + dis[0][i], ans);
    }
    cout << ans << '\n';
}

int main () {
    fastio;
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}