#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()
#define MP(x, y) make_pair((x), (y))

using namespace std;
typedef long long ll;

void solve () {
    int N; cin >> N;
    if (N == 0) return;
    vector<pii> arr(N);
    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        arr[i] = MP(w, i);
    }
    sort(ALL(arr));
    vector<pair<bool, int>> ans(N);
    ans[arr[0].second] = MP(0, 0);
    for (int i = 1; i < N; i++) {
        auto [w, idx] = arr[i];
        auto [prevw, prevIdx] = arr[i-1];
        if (w == prevw) {
            ans[idx] = MP(1, ans[prevIdx].second+1);
        } else {
            ans[idx] = MP(0, 0);
        }
    }
    for (auto [a, cnt] : ans) {
        if (a) cout << "Y " << cnt << '\n';
        else cout << "N\n";
    }
}

int main () {
    fastio;
    solve();
    return 0;
}