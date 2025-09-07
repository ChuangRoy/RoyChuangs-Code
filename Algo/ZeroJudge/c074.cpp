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
typedef long long int lli;

template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.first >> a.second;
}

void next_perm(vector<int> vec, vector<int> remaining) {
    if (SZ(vec) == 6) {
        for (int i = 0; i < 6; i++) {
            cout << vec[i] << " \n"[i==5];
        }
        return;
    }
    while (!remaining.empty() && SZ(vec) + SZ(remaining) >= 6) {
        vec.eb(remaining[0]);
        remaining.erase(remaining.begin());
        next_perm(vec, remaining);
        vec.erase(vec.end()-1);
    }
}

void solve() {
    int k;
    int t = 0;
    while (cin >> k, k) {
        if (t > 0) cout << '\n';
        vector<int> arr(k);
        for (auto &x : arr) {
            cin >> x;
        }
        next_perm({}, arr);
        t++;
    }
}

int main() {
    fastio;
    solve();
    return 0;
}