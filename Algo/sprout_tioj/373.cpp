#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) x.begin(), x.end()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

void solve () {
    int N, M;
    cin >> N >> M;
    vector<int> vec;
    auto addNum = [&](int num) -> void {
        if (num < M) return;
        vec.pb(num);
    };
    while (N--) {
        int k; cin >> k;
        addNum(2*k);
        addNum(k);
    }
    vector<int> dp;
    for (auto k : vec) {
        if (SZ(dp) == 0 || k >= dp.end()[-1]) {
            dp.pb(k);
        } else {
            auto replace = upper_bound(ALL(dp), k);
            *replace = k;
        }
    }
    cout << SZ(dp) << '\n';
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}