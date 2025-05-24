#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cstring>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;

int cnt[200005];

void dfs (vector<vector<int>> &adj, int cur, int parent) {
    cnt[cur] = 1;
    for (auto c : adj[cur]) {
        if (c == parent) continue;
        dfs(adj, c, cur);
        cnt[cur] += cnt[c];
    }
}

void solve () {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 2; i <= n; i++) {
        int k; cin >> k;
        adj[i].pb(k);
        adj[k].pb(i);
    }
    dfs(adj, 1, -1);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] - 1 << ' ';
    }
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
