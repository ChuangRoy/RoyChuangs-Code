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
    vector<int> rec;
    vector<int> pos(n+1);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pos[a] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i-1] > pos[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}