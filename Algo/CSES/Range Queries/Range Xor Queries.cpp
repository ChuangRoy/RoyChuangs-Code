#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

void add (vector<int> &tree, int n, int k, int x) {
    k += n;
    tree[k] = x ^ tree[k];
    while (k >= 1) {
        k /= 2;
        tree[k] = tree[2*k] ^ tree[2*k+1];
    }
}

int query (vector<int> &tree, int n, int l, int r) {
    l += n; r += n;
    int ret = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            ret = tree[l] ^ ret;
            l++;
        }
        if (r % 2 == 0) {
            ret = tree[r] ^ ret;
            r--;
        }
        l /= 2; r /= 2;
    }
    return ret;
}

int main () {
    AC
    int n, q;
    cin >> n >> q;
    vector<int> tree(2*n+10, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        add(tree, n, i, x);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(tree, n, a, b) << '\n';
    }
    return 0;
}