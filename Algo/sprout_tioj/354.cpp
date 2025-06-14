#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<lli, lli>
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long int lli;

unsigned long long get_distance_squared(pll A, pll B) {
    return SQ(A.first - B.first) + SQ(A.second - B.second);
}

void solve() {
    int N; cin >> N;
    map<unsigned long long, lli> distances_cnt;
    vector<pii> points;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        points.eb(MP(a, b));
    }
    lli ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            unsigned long long d = get_distance_squared(points[i], points[j]);
            ans += distances_cnt[d];
            // cerr << d << endl;
            distances_cnt[d]++;
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}