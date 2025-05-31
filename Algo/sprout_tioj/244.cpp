#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long int lli;

struct TRIE {
    int graph[1000006][26];
    int sz[1000006];
    int nodes;

    void init () {
        memset(graph, -1, sizeof(graph));
        memset(sz, 0, sizeof(sz));
        nodes = 1;
        sz[0] = 1000006;
    }
    
    bool existnxt (int id, int c) {
        return graph[id][c] != -1;
    }

    int getnxt (int id, int c) {
        if (existnxt(id, c)) return graph[id][c];
        nodes++;
        graph[id][c] = nodes - 1;
        return graph[id][c];
    }

    void insert (string s) {
        int id = 0;
        for (char c : s) {
            c -= 'a';
            id = getnxt(id, c);
            sz[id]++;
        }
    }
    
    int traversal (string s) {
        int id = 0;
        int steps = 0;
        for (char c : s) {
            c -= 'a';
            id = getnxt(id, c);
            steps++;
            if (sz[id] == 1) return steps;
        }
        return steps;
    }
} trie;

void solve () {
    trie.init();
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        trie.insert(s);
        ans += trie.traversal(s);
    }
    cout << ans << '\n';
}

int main () {
    fastio;
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}