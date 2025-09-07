#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> radix(10);
    int cur = 1;
    while (cur <= 1e9) {
        for (int i = 0; i < 10; i++) radix[i].clear();
        for (auto i : a) {
            radix[(i/cur)%10].pb(i);
        }
        a.clear();
        for (auto i : radix) {
            for (auto j : i) {
                a.pb(j);
            }
        }
        cur *= 10;
    }
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}