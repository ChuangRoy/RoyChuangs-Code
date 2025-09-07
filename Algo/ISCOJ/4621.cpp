#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define test(x) cerr << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) { \
    for (auto i : x) cout << i << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long int lli;

template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.first >> a.second;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector adj(N, vector<vector<pii>> (N, vector<pii> ()));
    vector alive(N, vector<bool> (N, 1));
    // (i, j) is alive : Si == Sj

    vector table(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int qij; cin >> qij;
            table[i][j] = qij;
        }
    }

    vector outputs(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int zij; cin >> zij;
            outputs[i][j] = zij;
        }
    }

    queue<pii> bfs;

    for (int i = 0; i < N; i++) {
        // alive[i][i] = 0;
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int a = min(table[i][k], table[j][k]);
                int b = max(table[i][k], table[j][k]);
                if (outputs[i][k] != outputs[j][k]) {
                    bfs.push(MP(i, j));
                }
                adj[a][b].eb(i, j);
            }
        }
    }

    while (!bfs.empty()) {
        auto [a, b] = bfs.front();
        bfs.pop();
        if (!alive[a][b]) continue;
        alive[a][b] = 0;
        for (auto [c, d] : adj[a][b]) {
            if (alive[c][d]) {
                bfs.push(MP(c, d));
            }
        }
    }

    bool flag = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (alive[i][j]) {
                flag = 1;
                cout << i << ' ' << j << '\n';
            }
        }
    }

    if (!flag) cout << "Emo Everyday\n";
}

int main() {
    fastio;
    solve();
    return 0;
}