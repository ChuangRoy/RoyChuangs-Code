#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstring>
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
typedef long long ll;

const int mod = 1e9 + 7;

struct mat {
    ll v[100][100];
    mat() {
        memset(v, 0, sizeof(v));
    };
};

mat mul (mat a, mat b, int N) {
    mat ret;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            ret.v[i][j] += a.v[i][k] * b.v[k][j];
            if (ret.v[i][j] >= mod) ret.v[i][j] %= mod;
        }
    }
    return ret;
}

mat power (mat &a, int k, int N) {
    mat ret;
    for (int i = 0; i < N; i++) ret.v[i][i] = 1;
    while (k) {
        if (k & 1) ret = mul(ret, a, N);
        a = mul(a, a, N);
        k >>= 1;
    }
    return ret;
}

void solve () {
    int N, M, L;
    cin >> N >> M >> L;
    mat G;
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.v[a][b] = 1;
    }
    G = power(G, L, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << G.v[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main () {
    fastio;
    solve();
    return 0;
}