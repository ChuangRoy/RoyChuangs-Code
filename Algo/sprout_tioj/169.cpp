#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define pb push_back
#define test(x) cerr << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) { \
	for (auto i : x) cout << i << ' '; \
	cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

void solve () {
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n+1);
    vector<ll> preSum(n+1, 0);
    vector<int> nums(n);
    for (auto &k : nums) cin >> k;
    reverse(ALL(nums));
    for (int i = 0; i < n; i++) preSum[i+1] = preSum[i] + nums[i];
    dp[0] = 0;
    deque<int> dq;
    dq.pb(0);
    for (int i = 1; i <= n; i++) {
        while (dq[0] < i - k) dq.pop_front();
        dp[i] = dp[dq[0]] + preSum[i];
        while (!dq.empty() && dp[dq.end()[-1]] <= dp[i]) dq.pop_back();
        dq.pb(i);
    }
    cout << dp[n] - preSum[n] << '\n';
}

int main () {
    fastio;
    solve();
    return 0;
}