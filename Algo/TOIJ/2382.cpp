#pragma GCC optimize("Ofast")
#include "lib2382.h"
#define pb emplace_back

using namespace std;

vector<int> v;
vector<vector<int>> adj;
vector<int> ans;
bool visited [10000] = {0};

void dfs (int cur, int parent) {
    ans[cur] = ans[parent] ^ v[cur];
    visited[ans[cur]] = 1;
    for (auto c : adj[cur]) {
        dfs(c, cur);
    }
}

void solve () {
    int n = Init();
    adj.resize(n);
    v.resize(n);
    ans.resize(n);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        int q = Ask(i, i, minIdx);
        if (q != 0) {
            v[i] = q;
            adj[minIdx].pb(i);
        } else {
            v[i] = 0;
            minIdx = i;
        }
    }
    ans[minIdx] = 0;
    visited[0] = 1;
    dfs(minIdx, minIdx);
    int prevMin = 0;
    for (int i = n - 1; i >= 0; i--) if (v[i] == 0 && i != minIdx) {
        for (int k = prevMin + 1; k < n; k++) {
            if (!visited[k]) {
                prevMin = k;
                break;
            }
        }
        ans[i] = prevMin;
        dfs(i, i);
    }
    Answer(ans);
}

int main () {
    solve();
    return 0;
}