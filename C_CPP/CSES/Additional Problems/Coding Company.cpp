#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;
long long dp[2][101][20001];
const int delta = 10000;

int main () {
    AC
    int n, x;
    cin >> n >> x;
    vector<int> t(n+1);
    t[0] = 0;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(ALL(t));
    memset(dp, 0, sizeof(dp));
    dp[0][0][delta] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = i % 2;
        int last = (i+1) % 2;
        for (int j = 0; j <= n - i + 1; j++) {
            for (int k = 0; k <= x + delta; k++) {
                dp[cur][j][k] = (dp[cur][j][k] + dp[last][j][k]) % mod;
                if (k + t[i] <= x + delta && j > 0)
                    dp[cur][j-1][k+t[i]] = (j * dp[last][j][k] + dp[cur][j-1][k+t[i]]) % mod;
                if (k - t[i] >= 0 && j <= n - i)
                    dp[cur][j+1][k-t[i]] = (dp[last][j][k] + dp[cur][j+1][k-t[i]]) % mod;
                if (j <= n - i + 2)
                    dp[cur][j][k] = (j * dp[last][j][k] + dp[cur][j][k]) % mod;
            }
        }
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= x + delta; k++) {
                dp[last][j][k] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= x + delta; i++) {
        ans = (dp[n%2][0][i] + ans) % mod;
    }
    cout << ans << '\n';
    return 0;
}