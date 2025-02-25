#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int j (int n, int k) {
    if (n == 1) return 1;
    int m = (n+1) / 2;
    if (k <= m) {
        if (2 * k == n + 1) {
            return 1;
        }
        return k * 2;
    }
    int temp = j(n / 2, k - m);

    if (n % 2) {
        return 2 * temp + 1;
    } else {
        return 2 * temp - 1;
    }

}

int main () {
    AC
    int q; cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << j(n, k) << '\n';
    }
    return 0;
}