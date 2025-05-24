#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[1<<20][20];
vector<vector<int>> adj(20);

int solve (int bitmask, int idx)
{
    if (idx == 0) {
        if (bitmask == 1) return 1;
        else return 0;
    }
    if (!(bitmask & (1<<idx))) return 0;
    if (dp[bitmask][idx] != -1) return dp[bitmask][idx];
    int mask_without_idx = bitmask ^ (1 << idx);
    int ans = 0;
    for (auto s : adj[idx]) {
        ans = (ans + solve(mask_without_idx, s)) % mod;
    }
    dp[bitmask][idx] = ans;
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b-1].push_back(a-1);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve((1<<n)-1, n-1) << '\n';
    return 0;
}