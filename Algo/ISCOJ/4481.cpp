#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long int lli;

struct TRIE {
    int graph[6000006][2];
    int nodes;

    void init () {
        memset(graph, -1, sizeof(graph));
        nodes = 1;
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
            c = (c=='p' ? 0 : 1);
            id = getnxt(id, c);
        }
    }
    
    unsigned long long int traversal (string s) {
        int id = 0;
        unsigned long long res = 0;
        for (char c : s) {
            res <<= 1;
            c = (c=='p' ? 0 : 1);
            int nxt = !c;
            if (existnxt(id, nxt)) {
                res |= 1;
                id = getnxt(id, nxt);
            } else {
                id = getnxt(id, c);
            }
        }
        return res;
    }
} trie;

void solve () {
    trie.init();
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        trie.insert(s);
    }
    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        cout << trie.traversal(s) << '\n';
    }
}

int main () {
    fastio;
    solve();
    return 0;
}