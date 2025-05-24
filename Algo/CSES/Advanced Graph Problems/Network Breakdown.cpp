#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) { // cin to pair
    return o >> a.first >> a.second;
}

struct DSU {
    int root[100005];

    void init (int n) {
        for (int i = 1; i <= n; i++) root[i] = i;
    }

    void unite (int a, int b) {
        // find roots
        a = find_root(a);
        b = find_root(b);
        root[b] = a; // merge root
    }

    int find_root (int x) {
        if (root[x] == x) return x;
        root[x] = find_root(root[x]); // pre save the roots
        return root[x];
    }

} dsu;
 
int main () {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    dsu.init(n);

    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        pair<int, int> e;
        cin >> e;
        if (e.first > e.second) swap(e.first, e.second); //為什麼會有人卡這種測資
        edges.insert(e);
    }

    // read all queries and process offline
    vector<pair<int, int>> queries(k);
    for (int i = 0; i < k; i++) {
        pair<int, int> e;
        cin >> e;
        if (e.first > e.second) swap(e.first, e.second);
        edges.erase(edges.find(e)); // remove the edge
        queries[i] = e;
    }

    // process DSU
    for (auto e : edges) {
        dsu.unite(e.first, e.second);
    }

    // counting components
    int components = 0;
    vector<bool> visited(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int root = dsu.find_root(i);
        if (!visited[root]) {
            components++;
            visited[root] = 1;
        }
    }

    vector<int> ans(k);
    // solving backward
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = components;
        auto [a, b] = queries[i];
        if (dsu.find_root(a) != dsu.find_root(b)) {
            // unite a, b if they aren't at the same component
            components--;
            dsu.unite(a, b);
        }
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k-1];
    }

    return 0;
}