#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

using namespace std;

void dfs (vector<vector<int>> &adj, vector<int> &rec, int cur, int num) {
    if (rec[cur] != -1) return;
    rec[cur] = num;
    for (auto i : adj[cur]) {
        dfs(adj, rec, i, num);
    }
}

int main () {
    AC
    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
    vector<vector<int>> adj(n);
    while (m--) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> rec(n, -1);
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (rec[i] != -1) continue;
        dfs(adj, rec, i, num);
        num++;
    }
    while (q--) {
        cin >> a >> b;
        a--; b--;
        if (rec[a] == rec[b]) {
            cout << "YES\n";
        } else {
            cout << "yes\n";
        }
    }
    return 0;
}