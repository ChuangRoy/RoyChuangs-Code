#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

void solve () {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<vector<ll>> dp(k+1, vector<ll> (n+1, 0));
    dp[0][a] = 1;
    for (int i = 0; i < k; i++) {
        vector<ll> diff(n+2, 0);
        for (int x = 1; x <= n; x++) {
            int dis = abs(b - x) - 1;
            int from = max(1, x - dis);
            int to = min(n, x + dis);
            diff[from] += dp[i][x];
            diff[x] -= dp[i][x];
            diff[x + 1] += dp[i][x];
            diff[to + 1] -= dp[i][x];
        }
        ll sum = 0;
        for (int y = 1; y <= n; y++) {
            sum += diff[y];
            dp[i+1][y] = sum;
            if (dp[i+1][y] >= mod) dp[i+1][y] %= mod;
        }
    }
    ll ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         if (i == b && j == 0) cout << "x ";
    //         else cout << dp[j][i] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
        if (ans >= mod) ans %= mod;
    }
    cout << ans << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
