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
    while (n--) {
        int x;
        cin >> x;
        if (x == 1) {
            cout << 1 << '\n';
            continue;
        }
        int root = sqrt(x);
        int cnt = 0;
        for (int i = 1; i <= root; i++) {
            if (x % i == 0) {
                cnt += 2;
            }
        }
        if (root * root == x && x >= 4) {
            cnt--;
        }
        cout << cnt << '\n';
    }
    return 0;
}