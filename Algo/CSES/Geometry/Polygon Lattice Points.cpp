#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void solve ();

struct pdd {
    ll X, Y;
    pdd (ll xx, ll yy) {
        X = xx, Y = yy;
    }
};

ll cross(pdd a, pdd b) {
    return a.X*b.Y - a.Y*b.X;
}

int main () {
    AC
    solve();
    return 0;
}

void solve () {
    int n;
    cin >> n;
    vector<pdd> v(n+1, pdd(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
    }
    v[n] = v[0];
    long long Area = 0;
    for (int i = 0; i < n; i++) {
        Area += cross(v[i], v[i+1]);
    }
    Area = labs(Area);
    Area /= 2;
    long long b = 0;
    for (int k = 0; k < n; k++) {
        b += __gcd <long long> (labs(v[k+1].X - v[k].X), labs(v[k+1].Y - v[k].Y));
    }
    cout << (Area + 1 - b / 2) << ' ' << b << '\n';
}