#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<int> values(n), weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<int> dp(w+1, 0);
    for (int i = 0; i < n; i++) {
        for (int k = w; k >= 0; k--) {
            if (k < weights[i]) break;
            dp[k] = max(dp[k], dp[k-weights[i]]+values[i]);
        }
    }
    cout << dp[w] << '\n';
    return 0;
}