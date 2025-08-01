#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
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
    string s;
    int N, L, R;
    cin >> N >> L >> R;
    L--; R--;
    cin >> s;
    bool ans = 1;
    for (int i = L; i <= R; i++) {
        if (s[i] == 'x') {
            ans = 0;
            break;
        }
    }
    if (ans) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fastio;
    solve();
    return 0;
}