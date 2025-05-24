#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
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
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(ALL(t));
    ll preSum = 0;
    for (int i = 0; i < n - 1; i++) {
        preSum += t[i];
    }
    if (preSum < t[n-1]) {
        cout << 2*t[n-1] << '\n';
    } else {
        cout << preSum + t[n-1] << '\n';
    }
}

int main () {
    AC
    solve();
    return 0;
}