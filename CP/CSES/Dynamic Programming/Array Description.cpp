#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main ()
{
    AC
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll> (m+2, 0));
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    if (x[0] == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    } else {
        dp[0][x[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (x[i]) {
            dp[i][x[i]] = ( dp[i-1][x[i]-1] 
                          + dp[i-1][x[i]] 
                          + dp[i-1][x[i]+1]
                          ) % mod;
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ( dp[i-1][j-1] 
                           + dp[i-1][j] 
                           + dp[i-1][j+1]
                           ) % mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}