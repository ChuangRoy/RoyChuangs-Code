#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int arr_size = 1e5;
bool visited[arr_size];

void dfs (int x, vector<vector<int>> &adj) {
    if (visited[x]) return;
    visited[x] = 1;
    for (auto n : adj[x]) {
        dfs(n, adj);
    }
}

int main () {
    AC
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> vertices;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        vertices.pb(i);
        cnt++;
        dfs(i, adj);
    }
    cout << cnt-1 << '\n';
    for (int i = 0; i < cnt - 1; i++) {
        cout << vertices[i]+1 << ' ' << vertices[i+1]+1 << '\n';
    }
    return 0;
}