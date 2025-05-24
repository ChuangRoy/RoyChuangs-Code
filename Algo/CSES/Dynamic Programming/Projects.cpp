#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

int main () {
    AC
    int n; cin >> n;
    map<int, int> compress;
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    int idx = 0;
    for (auto &v : compress) {
        v.second = idx;
        idx++;
    }
    vector<vector<pii>> project(idx);
    for (int i = 0; i < n; i++) {
        project[compress[b[i]]].pb(make_pair(compress[a[i]], p[i]));
    }
    vector<ll> dp(idx, 0);
    for (int i = 1; i < idx; i++) {
        dp[i] = dp[i-1];
        for (auto p : project[i]) {
            dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }
    cout << dp[idx-1] << '\n';
    return 0;
}