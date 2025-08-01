#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;

int main () {
    AC
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int> (b+1, INF));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) dp[i][j] = 0;
            else {
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[k][j]+dp[i-k][j]+1, dp[i][j]);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][k]+dp[i][j-k]+1, dp[i][j]);
                }
            }
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}