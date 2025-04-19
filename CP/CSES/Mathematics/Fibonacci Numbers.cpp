#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

struct matrix {
    ll v[2][2];
    matrix (int t) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                v[i][j] = t*(i == j);
            }
        }
    }
};

matrix mtxmul (matrix a, matrix b) {
    matrix c{0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c.v[i][j] += a.v[i][k] * b.v[k][j];
                if (c.v[i][j] >= mod) c.v[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix qpow (matrix a, ll k) {
    if (k <= 1) return a;
    matrix res{1};
    while (k) {
        if (k & 1) res = mtxmul(res, a);
        a = mtxmul(a, a);
        k >>= 1;
    }
    return res;
}

void solve () {
    ll n;
    cin >> n;
    if (n <= 1) {
        cout << n << '\n';
        return;
    }
    matrix org{0};
    org.v[0][0] = 1;
    org.v[0][1] = 1;
    org.v[1][0] = 1;
    org.v[1][1] = 0;
    matrix res = qpow(org, n - 1);
    cout << res.v[0][0] << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
