#include <bits/stdc++.h>

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

signed main ()
{
    AC
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    if (n == 1) {
        cout << max(x[0], 0LL) << '\n';
        return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = max(x[0], 0LL);
    dp[1] = max(dp[0], x[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + x[i]);
        // cout << dp[i] << '\n';
    }
    cout << dp[n-1] << '\n';
    return 0;
}