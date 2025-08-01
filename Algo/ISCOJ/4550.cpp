#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<lli> pre(N + 1);
    pre[0] = 0;
    for (int i = 0; i < N; i++) pre[i+1] = pre[i] + a[i];
    auto cost = [&] (int l, int r) -> lli { // cost [l, r]
        if (r - l + 1 < K) return inf;
        int mid = (l + r + 1) / 2;
        return (lli) (mid - l) * a[mid] - (pre[mid] - pre[l]) - (lli) (r - mid) * a[mid] + (pre[r + 1] - pre[mid + 1]);
    };
    vector<lli> dp(N + 1, inf);
    dp[0] = 0;
    auto f = [&] (int j, int i) -> lli {
        return dp[j] + cost(j, i);
    };
    int from = 0;
    for (int to = K - 1; to < N; to++) {
        int nxt = from;
        for (int j = from; j < to; j++) {
            if (f(j, to) < dp[to + 1]) {
                dp[to + 1] = f(j, to);
                nxt = j;
            }
        }
        from = nxt;
    }
    cout << dp[N] << '\n';
    return 0;
}