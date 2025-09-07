#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <utility>
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

void solve() {
    int N; cin >> N;
    vector<lli> ts(N), rs(N);
    for (auto &x : ts) cin >> x;
    for (auto &x : rs) cin >> x;
    int M; cin >> M;
    vector<lli> ss(M), es(M);
    for (int _i = 0; _i < M; _i++) cin >> ss[_i] >> es[_i];
    int cnt = 0;
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (ts[i] <= es[j] && ts[i] + rs[i] >= ss[j]) {
            cnt++;
            j++;
        } else if (ts[i] + rs[i] < es[j]){
            i++;
        } else {
            j++;
        }
    }
    cout << M - cnt << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}