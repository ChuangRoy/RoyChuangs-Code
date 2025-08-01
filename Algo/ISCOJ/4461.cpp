#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int main () {
    AC
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m;
    cin >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 0; j < m; j++) {
            sum += abs(x[j] - s[(i+j)%n]);
        }
        ans = min(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}