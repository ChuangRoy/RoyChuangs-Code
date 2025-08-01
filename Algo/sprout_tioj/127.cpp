#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#define AC cin.tie(nullptr) -> sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e7 + 9;
long long dp[100010];
int arr[100010];

void solve () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    cout << dp[n] << '\n'
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
