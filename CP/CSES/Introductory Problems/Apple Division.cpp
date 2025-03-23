#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int n; cin >> n;
    vector<int> p(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    ll ans = sum;
    for (int mask = 1; mask < (1<<n); mask++) {
        ll part = 0;
        for (int i = 0; i < n; i++) {
            if ((1<<i) & mask) {
                part += p[i];
            }
        }
        ans = min(abs(sum - part * 2), ans);
    }
    cout << ans << '\n';
    return 0;
}