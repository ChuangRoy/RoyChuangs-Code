#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* Template */
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ff first
#define ss second
#define AI(x) begin(x),end(x)
#define pb emplace_back
#ifdef LOCAL
#define debug(args...) LKJ("[ " #args " ]", args)
template<class I> void LKJ(I&&x) { cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t) { cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b) { while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
/* End of Template */

const ll inf = LLONG_MAX;

int main ()
{
    AC
    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> distance_cost(n, 0);
    for (int dis = 1; dis < n; dis++) {
        distance_cost[dis] = (dis/2) * (dis/2 + 1);
        if (dis % 2) distance_cost[dis] += (dis / 2 + 1);
    }

    /*
     * left | dp[j] | distance_cost | c[i] | right
     */

    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = c[i] + i * (i + 1) / 2; // left
        for (int j = 0; j < i; j++) {
            int dis = i - j - 1;
            dp[i] = min(dp[j] + distance_cost[dis] + c[i],
                            dp[i]);
        }
    }
    // right sum
    for (int i = 0; i < n; i++) {
        dp[i] += (n-i) * (n-i-1) / 2;
    }
    ll ans = inf;
    for (auto it : dp) ans = min(ans, it);
    cout << ans << '\n';
    return 0;
}