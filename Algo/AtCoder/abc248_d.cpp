#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

void solve () {
    int N; cin >> N;
    
    vector<int> A(N + 1);
    
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    int Q; cin >> Q;
    
    vector<vector<pair<int, int>>> queries_L(2e5 + 1);
    vector<vector<pair<int, int>>> queries_R(2e5 + 1);
    
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        queries_L[l].push_back({x, i});
        queries_R[r].push_back({x, i});
    }
    
    vector<int> cnt(2e5 + 1, 0);
    vector<int> ans(Q);
    
    for (int pos = 1; pos <= N; pos++) {
        for (auto [x, i] : queries_L[pos]) {
            ans[i] -= cnt[x];
        }
        cnt[A[pos]]++;
        for (auto [x, i] : queries_R[pos]) {
            ans[i] += cnt[x];
        }
    }

    for (auto i : ans) 
        cout << i << '\n';
}

int main () {
    solve();
    return 0;
}