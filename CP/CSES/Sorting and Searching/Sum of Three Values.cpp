#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

void solve () {
    int n; ll x;
    cin >> n >> x;
    vector<pair<ll, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(ALL(nums));
    for (int l = 0; l < n - 2; l++) {
        for (int r = l + 2; r < n; r++) {
            ll S_lr = nums[l].first + nums[r].first;
            if (S_lr == x) continue;
            if (x - S_lr < nums[l].first) continue;
            if (x - S_lr > nums[r].first) continue;
            int pos = lower_bound(nums.begin()+l+1,
                                  nums.begin()+r+1,
                                  make_pair(x - S_lr, 0)) - nums.begin();
            if (pos >= r || pos <= l) continue;
            if (S_lr + nums[pos].first == x) {
                cout << nums[l].second << ' ' << nums[pos].second << ' ' << nums[r].second << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main () {
    AC
    solve();
    return 0;
}