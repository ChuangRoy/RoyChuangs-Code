#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>
#define AC cin.tie(nullptr) -> sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9 + 10;

long long dp[100010];
long long arr[100010];

void solve () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 0;
    deque<pair<ll, ll>> dq;
    for (int i = 1; i <= k; i++) {
        while (SZ(dq) >= 1 and dq.end()[-1].first <= arr[i]) dq.pop_back();
        if (SZ(dq) >= 1)
            dp[i] = max(dq[0].first, arr[i]);
        else
            dp[i] = arr[i];
        dq.push_back(MP(dp[i], i));
    }
    for (int i = k + 1; i <= n; i++) {
        while (SZ(dq) >= 1 and dq[0].second <= i-k) dq.pop_front();
        if (SZ(dq) >= 1)
            dp[i] = max(dq[0].first, dp[i-k]+arr[i]);
        else
            dp[i] = dp[i-k]+arr[i];
        while (SZ(dq) >= 1 and dq.end()[-1].first <= dp[i]) dq.pop_back();
        dq.push_back(MP(dp[i], i));
    }
    cout << dp[n] << '\n';
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
