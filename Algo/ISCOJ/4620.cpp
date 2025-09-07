#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
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
typedef long long int lli;

template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.first >> a.second;
}

lli inf = 1e18;

bool eval(vector<int> &Vs, vector<int> &Cs, int &N, int &K, lli x) {
    vector<lli> dp(N);
    dp[0] = Vs[0] - x * Cs[0];
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i < N; i++) {
        while (dq.front() < i - K) dq.pop_front();
        dp[i] = dp[dq.front()] + Vs[i] - x * Cs[i];
        while (!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    // cerr << x << ' ' << dp[N-1] << endl;
    return dp[N-1] >= 0;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> Vs(N), Cs(N);
    for (auto &x: Vs) cin >> x;
    for (auto &x: Cs) cin >> x;
    // assume x is the answer
    // sum Vi - x * sum Ci >= 0
    // Vi - x * Ci as weight
    lli l = 0, r = 2e10;
    lli ans;
    while (l <= r) {
        lli mid = (l + r) >> 1;
        if (eval(Vs, Cs, N, K, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}