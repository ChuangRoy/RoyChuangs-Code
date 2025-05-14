#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#define AC cin.tie(0)->sync_with_stdio(false);

using namespace std;
typedef long long ll;

void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    map <int, int> freq;
    int l = 0, r = 0;
    int cnt = 0;
    ll ans = 0;
    while (r < n) {
        if (freq[arr[r]] == 0) {
            cnt++;
        }
        freq[arr[r]]++;
        while (cnt > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) {
                cnt--;
            }
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    cout << ans << '\n';
}

int main () {
    AC
    solve();
    return 0;
}