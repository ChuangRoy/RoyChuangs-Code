#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
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
    string s; cin >> s;
    string t = s;
    vector<int> hs;
    for (int i = 0; i < SZ(s); i++) {
        if (s[i] == '#') {
            hs.eb(i);
        }
    }
    hs.eb(SZ(s));
    // printv(hs);
    if (hs[0] - 1 >= 0 && s[hs[0] - 1] == '.') t[hs[0] - 1] = 'o';
    for (auto i : hs) {
        if (i + 1 < SZ(s) && s[i + 1] == '.') t[i + 1] = 'o';
        // cout << s[i + 1];
    }
    cout << t << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}