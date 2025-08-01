#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> tasks(3, vector<int> (n+1));
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> tasks[k][i];
        }
    }
    vector<vector<int>> dp(3, vector<int> (n+1, 0));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + tasks[0][i];
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + tasks[1][i];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + tasks[2][i];
    }
    cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << '\n';
    return 0;
}