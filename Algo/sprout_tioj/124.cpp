#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e6 + 7;

int maxn = 0;
int T;

long long dp[100010];
int queries[100000];

void solve () {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[2] = 3;
    long long sum = 0;
    for (int i = 4; i <= maxn; i+=2) {
        sum += dp[i-4];
        if (sum >= mod) sum %= mod;
        dp[i] = dp[i-2] * 3 + 2 * sum;
        if (dp[i] >= mod) dp[i] %= mod;
    }
    for (int k = 0; k < T; k++) {
        cout << dp[queries[k]] << '\n';
    }
}

int main () {
    AC
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        queries[i] = n;
        maxn = max(maxn, n);
    }
    solve();
    return 0;
}
