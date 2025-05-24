#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define SZ(x) ((int) x.size())

using namespace std;

void solve () {
    int N, M;
    string A, B;
    cin >> N >> M;
    vector dp(N+1, vector<string> (M+1));
    cin >> A >> B;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            vector<string> candidates;
            if (A[i-1] == B[j-1]) {
                candidates.eb(dp[i-1][j-1] + A[i-1]);
            }
            candidates.eb(dp[i-1][j]);
            candidates.eb(dp[i][j-1]);
            sort(ALL(candidates), [] (auto a, auto b) {
                if (SZ(a) == SZ(b)) return a < b;
                else return (SZ(a) > SZ(b));
            });
            dp[i][j] = candidates[0];
        }
    }
    if (SZ(dp[N][M]) == 0) cout << "7122\n";
    else cout << dp[N][M] << '\n';
}

int main () {
    fastio;
    solve();
    return 0;
}