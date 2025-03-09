#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

bool check (int &n, vector<pair<ll, ll>> &p, vector<int> &c, ll &m, int &k)
{
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = p[i].first + p[i].second * m;
    }
    sort(arr.begin(), arr.end(), [](auto a, auto b) {
        return a > b;
    });
    int l = 0, r = 0;
    int cnt = 0;
    while (r < n && cnt < k) {
        if (cnt + n - r < k) break;
        if (arr[l] > c[r]) {
            l++; r++;
            cnt++;
        } else {
            r++;
        }
    }
    if (cnt >= k) return 1;
    else return 0;
}

signed main ()
{
    AC
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> p(n);
        vector<int> c(n);
        int ai, bi;
        for (int i = 0; i < n; i++) {
            cin >> ai >> bi;
            p[i] = make_pair(ai, bi);
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        sort(c.begin(), c.end(), [](auto a, auto b) {
            return a > b;
        });

        ll l = 0, r = 2e9;
        ll mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (check(n, p, c, mid, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (check(n, p, c, r, k)) {
            cout << r << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}