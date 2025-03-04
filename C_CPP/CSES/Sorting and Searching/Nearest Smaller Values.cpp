#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int main () {
    AC
    int n; cin >> n;
    vector<int> x(n+1);
    vector<int> idx(n+1);
    x[0] = 0;
    idx[0] = 0;
    int r = 0;
    for (int i = 1; i <= n ; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        while(x[idx[r]] >= x[i]) r--;
        cout << idx[r] << ' ';
        r++;
        idx[r] = i;
    }
    cout << '\n';
    return 0;
}