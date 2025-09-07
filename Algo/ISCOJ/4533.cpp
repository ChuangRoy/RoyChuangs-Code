#include <bits/stdc++.h>

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

signed main ()
{
    AC
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = a[0], ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (sum > k) {
            if (l < r) {
                sum -= a[l];
                l++;
            } else {
                l++; r++;
                if (r < n) sum = a[r];
            }
        } else {
            // cout << l << r << sum << '\n';
            ans += (r - l + 1);
            r++;
            if (r < n) sum += a[r];
        }
    }
    cout << ans << '\n';
    return 0;
}