#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    int q, k;
    cin >> q >> k;
    int cnt = 0;
    ll delta = 0;
    priority_queue<ll> pq;
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            ll x; cin >> x;
            pq.push(x-delta);
            cnt++;
            if (cnt > k) {
                pq.pop();
            }
        } else if (opt == 2) {
            ll y; cin >> y;
            delta += y;
        } else {
            if (cnt < k) cout << "No solution\n";
            else cout << pq.top() + delta << '\n';
        }
    }
}

int main () {
    AC
    solve();
    return 0;
}