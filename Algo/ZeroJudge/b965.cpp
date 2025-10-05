#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define test(x) cerr << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x)                                  \
        {                                          \
                for (auto i : x) cout << i << ' '; \
                cout << endl;                      \
        }
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x) * (x))
#define SZ(x) ((int)x.size())

using namespace std;
typedef long long int lli;

template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
        return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
        return o >> a.first >> a.second;
}

typedef vector<vector<int>> mat;

mat rotate_left(mat v) {
        int R = SZ(v);
        int C = SZ(v[0]);
        mat res(C, vector<int>(R));
        for (int i = 0; i < C; i++) {
                for (int j = 0; j < R; j++) {
                        res[i][j] = v[j][C - i - 1];
                }
        }
        return res;
}

mat flip(mat v) {
        int R = SZ(v);
        int C = SZ(v[0]);
        mat res(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
                res[i] = v[R - i - 1];
        }
        return res;
}

void solve() {
        int R, C, M;
        cin >> R >> C >> M;
        mat v(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                        cin >> v[i][j];
                }
        }
        vector<int> ms(M);
        for (int k = 0; k < M; k++) {
                cin >> ms[k];
        }
        for (int k = M - 1; k >= 0; k--) {
                if (ms[k]) {
                        v = flip(v);
                } else {
                        v = rotate_left(v);
                }
        }
        R = SZ(v);
        C = SZ(v[0]);
        cout << R << ' ' << C << '\n';
        for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                        cout << v[i][j];
                        if (j != C - 1)
                                cout << ' ';
                        else if (i != R - 1)
                                cout << '\n';
                }
        }
}

int main() {
        fastio;
        solve();
        return 0;
}