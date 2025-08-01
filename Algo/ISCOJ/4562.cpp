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
    int n, q;
    cin >> n >> q;
    int *pre = new int[n];
    int a, b; cin >> a;
    pre[0] = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        pre[i] = a ^ pre[i-1];
    }
    while (q--) {
        cin >> a >> b;
        if (a == 0) {
            cout << pre[b] << '\n';
        } else {
            cout << (pre[b] ^ pre[a-1]) << '\n';
        }
    }
    delete[] pre;
    return 0;
}