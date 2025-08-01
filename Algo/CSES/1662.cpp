#pragma GCC optimize("Ofast")
#include <iostream>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

int memo [200005] = {0}; // store mods

void solve () {
    int n;
    cin >> n;
    ll sum = 0;
    memo[0] = 1;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        while (sum < 0) sum += n;
        if (sum >= n) sum %= n;
        cnt += memo[sum];
        memo[sum]++;
    }
    cout << cnt << '\n';
}

int main () {
    AC
    solve();
    return 0;
}