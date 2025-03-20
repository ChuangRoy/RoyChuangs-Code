#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define DSU

using namespace std;
int father[2000000];

int find_root (int i) {
    if (father[i] == i) {
        return i;
    } else {
        int root = find_root(father[i]);
        father[i] = root;
        return root;
    }
}

void union_ab (int a, int b) {
    int root_x = find_root(a);
    int root_y = find_root(b);
    father[root_x] = root_y;
}

void dfs (vector<vector<int>> &adj, vector<int> &rec, int cur, int num) {
    if (rec[cur] != -1) return;
    rec[cur] = num;
    for (auto i : adj[cur]) {
        if (rec[i] != -1) continue;
        dfs(adj, rec, i, num);
    }
}

int main () {
    AC
    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
#ifndef DSU
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
#else
    for (int i = 0; i < 2000000; i++) {
        father[i] = i;
    }
    while (m--) {
        cin >> a >> b;
        a--; b--;
        union_ab(a, b);
    }
    while (q--) {
        cin >> a >> b;
        a--; b--;
        if (find_root(a) == find_root(b)) {
            cout << "YES\n";
        } else {
            cout << "yes\n";
        }
    }
#endif
    return 0;
}