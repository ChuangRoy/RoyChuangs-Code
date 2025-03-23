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
    int m, s, t;
    cin >> m >> s >> t;
    vector<int> dis(t + 5, 0);
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            dis[i] = dis[i-1] + 60;
            m -= 10;
        } else {
            m += 4;
            dis[i] = dis[i-1];
        }
    }
    for (int i = 1; i <= t; i++) {
        dis[i] = max(dis[i-1]+17, dis[i]);
        if (dis[i] >= s) {
            cout << "Yes\n";
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No\n";
    cout << dis[t] << '\n';
    return 0;
}