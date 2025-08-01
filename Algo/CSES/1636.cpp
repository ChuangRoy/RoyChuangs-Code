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
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    vector<int> ci(n);
    for (int i = 0; i < n; i++) cin >> ci[i];
    sort(ci.begin(), ci.end());
    for (auto c : ci) {
        for (int i = 0; i < c; i++) {
            for (int j = i; j <= x - c; j+=c) {
                dp[j+c] = (dp[j+c] + dp[j]) % mod;
            }
        }
    }
    // for (int i = 1; i <= x; i++) cout << dp[i] << ' ';
    cout << dp[x] << '\n';
    return 0;
}