#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> rec(n+1, make_pair(-1, 1)); // prev, cnt
        int prev, y;
        while (m--) {
            cin >> prev >> y;
            rec[y].first = prev;
            while (prev != -1) {
                rec[prev].second += rec[y].second;
                prev = rec[prev].first;
            }
        }
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;
            cout << rec[x].second << '\n';
        }
    }
    return 0;
}