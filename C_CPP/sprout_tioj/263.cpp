#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans;
int min_value;

int dfs(vector<vector<int>> &adj, int &N, int cur, int parent) {
    int b = 0;
    int subTreeSize = 1;
    for (auto c : adj[cur]) {
        if (c == parent) continue;
        int size = dfs(adj, N, c, cur);
        b = max(size, b);
        subTreeSize += size;
    }
    b = max(b, N - subTreeSize);
    if (b < min_value || (b == min_value && cur < ans)) {
        ans = cur;
        min_value = b;
    }
    return subTreeSize;
}

int main () {
    AC
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<vector<int>> adj(N);
        int a, b;
        for (int i = 0; i < N-1; i++) {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        min_value = 1e9;
        ans = 1e9;
        dfs(adj, N, 0, -1);
        cout << ans << '\n'; 
    }   
    return 0;
}