#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;

typedef long long lli;

const int mod = 1e9 + 7;

struct Graph {
    lli ways_to[2003][2003];
    bool blocked[2003][2003];
    int N, M;
    
    void init(int n, int m) {
        N = n, M = m;
        memset(blocked, 0, sizeof(blocked));
        for (int i = 0; i <= N; i++) ways_to[i][0] = 0;
        for (int j = 0; j <= M; j++) ways_to[0][j] = 0;
        ways_to[1][1] = 1;
    }
    
    void add_block(int x, int y) {
        blocked[y][x] = 1;
    }
    
    bool is_blocked(int x, int y) {
        return blocked[y][x];
    }
    
    void process_dp() {
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                if (x == 1 && y == 1) continue;
                if (is_blocked(x, y)) {
                    ways_to[y][x] = 0;
                } else {
                    ways_to[y][x] = (ways_to[y-1][x] + ways_to[y][x-1]) % mod;
                }
            }
        }
    }
    
    int get_ways_to(int x, int y) {
        return ways_to[y][x];
    }

} graph;

using namespace std;
typedef long long int lli;

void solve() {
    int N, M, R;
    cin >> N >> M >> R;
    graph.init(N, M);
    while (R--) {
        int x, y;
        cin >> y >> x;
        graph.add_block(x, y);
    }
    graph.process_dp();
    int paths_count = graph.get_ways_to(M, N);
    if (paths_count > 0) cout << paths_count << '\n';
    else cout << "Path No Found.\n";
}

int main() {
    fastio;
    solve();
    return 0;
}