#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define test(x) cerr << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) { \
	for (auto i : x) cout << i << ' '; \
	cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;

template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.first >> a.second;
}

void solve () {
    int N, M;
    cin >> N >> M;
    vector<bool> dp(M+1, 0);
    vector<pii> coins(N);
    sort(rALL(coins));
    dp[0] = 1;
    for (int i = 0; i < N; i++) cin >> coins[i];
    for (auto [ci, ki] : coins) {
        if (ci > M) continue;
        for (int cnt = 1; ki > 0; cnt <<= 1) {
            int take = min(ki, cnt);
            for (int val = M; val >= ci*take; val--) {
                dp[val] = dp[val] | dp[val - ci*take];
            }
            if (dp[M] == 1) {
                cout << "Yes\n";
                return;
            }
            ki -= take;
        }
    }
    cout << "No\n";
}

int main () {
    fastio;
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}