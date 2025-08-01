#include <bits/stdc++.h>
using namespace std;
#define int long long

const int dp_size = 1e5 + 1;
const int inf = 1e9 + 1;

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<int> dp(dp_size, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int wei, val;
        cin >> wei >> val;
        for (int k = dp_size - 1; k >= val; k--) {
            dp[k] = min(dp[k], dp[k-val]+wei);
        }
    }
    int ans;
    for (int i = 0; i < dp_size; i++) {
        if (dp[i] <= w) ans = i;
    }
    cout << ans << '\n';
    return 0;
}