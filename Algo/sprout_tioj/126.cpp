#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

const int mod = 1e6 + 7;

int queries[100000];
int T;
int maxN = 0;

long long dp0[100000][3];
long long dp1[100000][3];

// green red blue

void solve () {
    dp0[0][0] = 1;
    dp0[0][1] = 0;
    dp0[0][2] = 0;
    for (int i = 1; i < maxN; i++) {
        dp0[i][0] = dp0[i-1][0] + dp0[i-1][1];
        dp0[i][1] = dp0[i-1][0] + dp0[i-1][1] + dp0[i-1][2];
        dp0[i][2] = dp0[i-1][1] + dp0[i-1][2];
        if (dp0[i][0] >= mod) dp0[i][0] %= mod;
        if (dp0[i][1] >= mod) dp0[i][1] %= mod;
        if (dp0[i][2] >= mod) dp0[i][2] %= mod;
    }
    dp1[0][0] = 0;
    dp1[0][1] = 1;
    dp1[0][2] = 0;
    for (int i = 1; i < maxN; i++) {
        dp1[i][0] = dp1[i-1][0] + dp1[i-1][1];
        dp1[i][1] = dp1[i-1][0] + dp1[i-1][1] + dp1[i-1][2];
        dp1[i][2] = dp1[i-1][1] + dp1[i-1][2];
        if (dp1[i][0] >= mod) dp1[i][0] %= mod;
        if (dp1[i][1] >= mod) dp1[i][1] %= mod;
        if (dp1[i][2] >= mod) dp1[i][2] %= mod;
    }
}

int main () {
    AC
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        maxN = max(queries[i], maxN);
    }
    solve();
    for (int i = 0; i < T; i++) {
        int cur = queries[i] - 1;
        long long ans = (dp0[cur][0] + dp0[cur][1]) * 2;
        if (ans >= mod) ans %= mod;
        ans += (dp1[cur][0] + dp1[cur][1] + dp1[cur][2]);
        if (ans >= mod) ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}