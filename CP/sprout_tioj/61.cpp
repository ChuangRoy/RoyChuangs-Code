#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void getPerm (vector<int> &nums, int k, int cur, int cntdown, vector<int> rec) {
    if (cur >= k) return;
    if (cntdown == 1) {
        for (auto it : rec) cout << it << ' ';
        cout << nums[cur] << '\n';
        return;
    }
    rec.pb(nums[cur]);
    for (int i = cur + 1; i <= k - cntdown + 1; i++) {
        getPerm(nums, k, i, cntdown - 1, rec);
    }
}

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector<int> nums(k);
        for (int i = 0; i < k; i++) cin >> nums[i];
        vector<int> rec;
        for (int i = 0; i <= k - 6; i++) {
            getPerm(nums, k, i, 6, rec);
        }
    }
    return 0;
}