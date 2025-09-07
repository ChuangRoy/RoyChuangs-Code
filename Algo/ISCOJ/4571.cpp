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
    int N; cin >> N;
    string s;
    cin >> s;
    lli sum = 0;
    for (auto c : s) {
        if (c == '+') sum += 30;
        if (c == '-') sum += 70;
        if (c == '*') sum += 500;
    }
    int res = sum / N;
    if (res <= 33) cout << "tsai\n";
    else if (res <= 66) cout << "have toppings\n";
    else cout << "niubee\n";
}

int main() {
    fastio;
    solve();
    return 0;
}