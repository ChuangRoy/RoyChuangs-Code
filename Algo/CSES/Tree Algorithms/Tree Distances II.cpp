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
typedef long long ll;

vector<vector<int>> adj;
int N;
int sz [200005];
ll dp [200005];
int visited [200005];

void dfs (int cur, int parent, int d) {
    dp[1] += d;
    sz[cur] = 1;
    for (auto c : adj[cur]) if (c != parent) {
        dfs(c, cur, d + 1);
        sz[cur] += sz[c];
    }
}

void getAns (int cur, int parent) {
    for (auto c : adj[cur]) if (c != parent) {
        dp[c] = dp[cur] + (N - sz[c]) - sz[c];
        getAns(c, cur);
    }
}

void solve () {
    memset(visited, 0, sizeof(visited));
    cin >> N;
    adj.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 1, 0);
    visited[1] = 1;
    getAns(1, 1);
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
