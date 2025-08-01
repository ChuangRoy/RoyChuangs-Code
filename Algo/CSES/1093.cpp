#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;

int main () {
    AC
    int n; cin >> n;
    int target = n * (n+1) / 2;
    if (target % 2) {
        cout << 0 << '\n';
        return 0;
    }
    target /= 2;
    vector<long long> dp(target+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << (dp[target] * 500000004) % mod << '\n';
    return 0;
}