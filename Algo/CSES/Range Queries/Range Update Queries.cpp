#include <bits/stdc++.h>
using namespace std;

void add (vector<long long> &tree, int &n, int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += (k & -k);
    }
}

long long prefix_sum (vector<long long> &tree, int &n, int k) {
    long long ret = 0;
    while (k >= 1) {
        ret += tree[k];
        k -= (k & -k);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1, 0);
    vector<long long> tree(n+10, 0);
    for (int i = 1; i <= n; i++) {
         cin >> a[i];
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            add(tree, n, a, u);
            add(tree, n, b+1, -u);
        } else {
            int k;
            cin >> k;
            cout << a[k] + prefix_sum(tree, n, k) << '\n';
        }
    }
    return 0;
}