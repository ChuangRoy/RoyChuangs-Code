#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <climits>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

ll eval (pair<ll, ll> from, int i, int C) {
    int dis = i - from.second;
    return (ll) from.first - dis * C;
} 

void solve () {
    int N, K, C;
    cin >> N >> K >> C;
    priority_queue<pair<ll, ll>> pq;
    vector<ll> var(N);
    vector<ll> dp(N);
    for (int i = 0; i < N; i++) {
        cin >> var[i];
    }
    dp[0] = var[0];
    pq.push(MP(dp[0], 0));
    for (int i = 1; i < N; i++) {
        while (pq.top().second < i - K) pq.pop();
        auto from = pq.top();
        // cerr << from.first << ' ' << from.second << endl;
        dp[i] = max(var[i], var[i] + eval(from, i, C));
        // cerr << dp[i] << endl;
        while (!pq.empty() && eval(pq.top(), i, C) <= dp[i]) pq.pop();
        pq.push(MP(dp[i], i));
    }
    ll ans = 0;
    for (auto k : dp) ans = max(k, ans);
    cout << ans << '\n';
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}