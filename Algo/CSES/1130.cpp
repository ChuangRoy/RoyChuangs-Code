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
 
int ans = 0;
bool visited[200005] = {0};
vector<vector<int>> adj;
int n;

void dfs (int cur, int parent) {
    for (auto c : adj[cur]) if (c != parent) {
        dfs(c, cur);
        if (!visited[cur] && !visited[c]) {
            visited[cur] = 1;
            visited[c] = 1;
            ans++;
        }
    }
}
 
void solve () {
    int n; cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 1);
    cout << ans << '\n';
}
 
int main () {
    AC
    solve();
    return 0;
}