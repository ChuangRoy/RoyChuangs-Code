#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;
typedef long long ll;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int main () {
    AC
    auto seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> pos(3e5 + 1);
    vector<int> a(n);
    int ai;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        pos[ai].pb(i);
        a[i] = ai;
    }
    int k;
    while (q--) {
        int ans = 0;
        int l, r;
        cin >> l >> r;
        l--; r--;
        int Orz, pos_l, pos_r;
        k = 30;
        int target = r - l + 1;
        for (int j = 0; j < k; j++) {
            int idx = uniform_int_distribution<int>(l, r)(rng);
            Orz = a[idx];
            if (int(pos[Orz].size())*2 >= target) {
                pos_l = lower_bound(pos[Orz].begin(), pos[Orz].end(), l) - pos[Orz].begin();
                pos_r = upper_bound(pos[Orz].begin(), pos[Orz].end(), r) - pos[Orz].begin() - 1;
                if ((pos_r - pos_l + 1) * 2 > target) {
                    ans = Orz;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}