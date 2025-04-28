#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n+1);
    vector<int> pos(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nums[i] = x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i+1]) {
            ans++;
        }
    }
    while (m--) {
        set<pii> numPairs;
        int l, r;
        cin >> l >> r;
        if (nums[l] > 1) {
            numPairs.insert(MP(nums[l] - 1, nums[l]));
        }
        if (nums[l] < n) {
            numPairs.insert(MP(nums[l], nums[l] + 1));
        }
        if (nums[r] > 1) {
            numPairs.insert(MP(nums[r] - 1, nums[r]));
        }
        if (nums[r] < n) {
            numPairs.insert(MP(nums[r], nums[r] + 1));
        }
        for (auto it : numPairs) {
            if (pos[it.first] > pos[it.second]) {
                ans--;
            }
        }
        swap(nums[l], nums[r]);
        pos[nums[l]] = l;
        pos[nums[r]] = r;
        for (auto it : numPairs) {
            if (pos[it.first] > pos[it.second]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}

int main () {
    AC
    solve();
    return 0;
}