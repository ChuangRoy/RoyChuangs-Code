#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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

string S[10];
vector<string> strs;

void recur(vector<int> seq, int cntdown, int N) {
    if (cntdown == 0) {
        string res = "";
        for (auto i : seq) {
            res += S[i];
        }
        strs.eb(res);
    } else {
        for (int i = 0; i < N; i++) {
            vector<int> seq2 = seq;
            seq2.eb(i);
            recur(seq2, cntdown - 1, N);
        }
    }
}

void solve() {
    int N, K, X;
    cin >> N >> K >> X;
    for (int i = 0; i < N; i++) cin >> S[i];
    recur({}, K, N);
    // printv(strs);
    sort(ALL(strs));
    cout << strs[X-1] << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}