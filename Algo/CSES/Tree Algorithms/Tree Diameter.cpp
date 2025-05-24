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

int maxDis = 0, farthest;

void dfs (vector<vector<int>> &adj, int cur, int parent, int dis) {
    if (dis > maxDis) {
        maxDis = dis;
        farthest = cur;
    }
    for (auto c : adj[cur]) {
        if (c == parent) continue;
        dfs(adj, c, cur, dis + 1);
    }
}

void solve () {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(adj, 1, -1, 0);
    maxDis = 0;
    dfs(adj, farthest, -1, 0);
    cout << maxDis << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
