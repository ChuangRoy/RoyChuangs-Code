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

int N;
vector<vector<int>> adj;
int path[200005], maxDist[200005], secDist[200005];

void dfsDown (int cur, int parent) {
    maxDist[cur] = 0;
    secDist[cur] = 0;
    for (auto c : adj[cur]) if (c != parent) {
        dfsDown(c, cur);
        if (maxDist[c] + 1 > maxDist[cur]) {
            secDist[cur] = maxDist[cur]; 
            maxDist[cur] = maxDist[c] + 1;
            path[cur] = c;
        } else if (maxDist[c] + 1 > secDist[cur]) {
            secDist[cur] = maxDist[c] + 1;
        }
    }
}

void dfsUp (int cur, int parent) {
    for (auto c : adj[cur]) if (c != parent) {
        if (path[cur] == c) {
            if (secDist[cur] + 1 > maxDist[c]) {
                path[c] = cur;
                secDist[c] = maxDist[c];
                maxDist[c] = secDist[cur] + 1;
            } else if (secDist[cur] + 1 > secDist[c]) {
                secDist[c] = secDist[cur] + 1;
            }
        } else {
            secDist[c] = maxDist[c];
            maxDist[c] = maxDist[cur] + 1;
            path[c] = cur;
        }
        dfsUp(c, cur);
    }
}

void solve () {
    cin >> N;
    adj.resize(N+1);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfsDown(1, 1);
    dfsUp(1 ,1);
    for (int i = 1; i <= N; i++) {
        cout << maxDist[i] << ' ';
    }
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
