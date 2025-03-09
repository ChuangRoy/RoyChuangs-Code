#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int main () {
    AC
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = n-k+1; i <= n; i++) {
        ans = (ans + m) % i;
    }
    cout << ans+1 << '\n';
    return 0;
}