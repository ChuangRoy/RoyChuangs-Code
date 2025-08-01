#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vector<int> color(n, -1);
        bool normal = 1;
        for (int i = 0; i < n && normal; i++) {
            if (color[i] != -1) continue;
            queue<int> nxts;
            // stack<int> nxts
            nxts.push(i);
            color[i] = 1;
            while (!nxts.empty() && normal) {
                int cur = nxts.front();
                nxts.pop();
                for (auto k : adj[cur]) {
                    if (color[k] == -1) {
                        color[k] = 3 - color[cur];
                        nxts.push(k);
                    } else if (color[k] == color[cur]) {
                        normal = 0;
                        cout << "RAINBOW.\n";
                        break;
                    }
                }
            }
        }
        if (normal) cout << "NORMAL.\n";
    }
    return 0;
}