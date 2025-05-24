#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int n; cin >> n;
    map<int, int> mp; // num, prev
    int ans = 0;
    int begin = 1;
    for (int i = 1 ; i <= n; i++) {
        int a;
        cin >> a;
        if (!mp[a]) {
            mp[a] = i;
        } else {
            if (mp[a] < begin) {
                mp[a] = i;
            } else {
                begin = mp[a] + 1;
                mp[a] = i;
            }
        }
        ans = max(i-begin+1, ans);
    }
    cout << ans << '\n';
    return 0;
}