#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

void solve () {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    vector<vector<pair<int, int>>> R(2e5 + 1);
    vector<int> dp;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) {
        int r, x;
        cin >> r >> x;
        R[r].eb(x, i);
    }
    vector<int> ans(Q);
    for (int i = 1; i <= N; i++) {
        if (dp.empty() || dp.end()[-1] < A[i]) {
            dp.eb(A[i]);
        } else {
            auto replace = lower_bound(ALL(dp), A[i]);
            *replace = A[i];
        }
        for (auto [x, idx] : R[i]) {
            ans[idx] = upper_bound(ALL(dp), x) - dp.begin();
        }
    }

    for (auto k : ans) cout << k << '\n';
}

int main () {
    fastio;
    solve();
    return 0;
}