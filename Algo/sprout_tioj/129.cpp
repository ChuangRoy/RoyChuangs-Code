#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <cstring>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

int a[100];
int dp[100][100];
int preSum[101];

void solve () {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    memset(dp, 0x3f, sizeof(dp));
    preSum[0] = 0;
    int sum = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (len == 1) {
                sum += a[i];
                preSum[i+1] = sum;
                dp[i][i] = 0;
                continue;
            }
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][k] + dp[k+1][j] + preSum[j+1] - preSum[i], dp[i][j]);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}