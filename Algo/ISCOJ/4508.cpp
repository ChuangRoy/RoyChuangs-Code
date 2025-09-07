#pragma gcc optimize("Ofast")
#include <iostream>
#include <vector>
#define pb emplace_back
using namespace std;

int visited_cnt = 0;

void dfs (int cur, vector<vector<int>> &adj, vector<bool> &visited) {
    if (visited[cur]) return;
    visited_cnt++;
    visited[cur] = 1;
    for (auto nxt : adj[cur]) {
        if (!visited[nxt])
            dfs(nxt, adj, visited);
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int V, E;
    cin >> V >> E;
    vector<bool> visited(V, 0);
    vector<vector<int>> adj(V);
    int cnt = 0;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if (E > 0)
        dfs(0, adj, visited);
    int q;
    cin >> q;
    if (V == visited_cnt) {
        for (int i = 0; i < q; i++) cout << "No\n";
    } else {
        for (int i = 0; i < q; i++) cout << "Yes\n";
    }
    return 0;
}
