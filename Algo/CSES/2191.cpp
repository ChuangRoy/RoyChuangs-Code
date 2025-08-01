#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
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
    vector<pdd> v(n, pdd(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
    }
    long long Area = 0;
    for (int i = 0; i < n - 1; i++) {
        Area += cross(v[i], v[i+1]);
    }
    Area += cross(v[n-1], v[0]);
    cout << labs(Area) << '\n';
}