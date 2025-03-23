#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
int a[40];

int main () {
    AC
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> s1, s2;
    for (int i = 0; i < n; i++) cin >> a[i];
    int half = (n+1) / 2;
    for (int mask = 0; mask < (1 << half); mask++) {
        ll sum = 0;
        for (int i = 0; i < half; i++) {
            if ((1 << i) & mask) {
                sum += a[i];
            }
        }
        s1.pb(sum);
    }
    int remains = n - half;
    for (int mask = 0; mask < (1 << remains); mask++) {
        ll sum = 0;
        for (int i = 0; i < remains; i++) {
            if ((1 << i) & mask) {
                sum += a[half+i];
            }
        }
        s2.pb(sum);
    }
    sort(ALL(s1));
    sort(ALL(s2));
    ll ans = 0;
    for (auto i : s1) {
        auto highIt = upper_bound(s2.begin(), s2.end(), x - i);
        auto lowIt = lower_bound(s2.begin(), s2.end(), x - i);
        ans += highIt - lowIt;
    }
    cout << ans << '\n';
    return 0;
}