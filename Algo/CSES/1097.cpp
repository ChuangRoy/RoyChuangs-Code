#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

int main () {
    AC
    int n; cin >> n;
    vector<int> x(n+1);
    ll sum = 0;
    vector<vector<ll>> diff(n+2, vector<ll> (n+2, 0));
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    for (int r = 1; r <= n; r++) {
        for (int l = r; l >= 1; l--) {
            if (l == r) {
                diff[l][r] = x[l];
            } else {
                diff[l][r] = max(x[l]-diff[l+1][r], x[r]-diff[l][r-1]);
            }
        }
    }
    cout << (sum + diff[1][n]) / 2 << '\n';
    return 0;
}