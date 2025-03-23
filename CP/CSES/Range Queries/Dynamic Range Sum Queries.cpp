#include <bits/stdc++.h>
using namespace std;

vector<long long> tree(2e5+1, 0);

long long sum(int k) {
    long long ret = 0; // return
    while (k) { // while k >= 1
    	ret += tree[k];
        k -= k & -k;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int x, k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        k = i;
        while (k <= n) {
        	tree[k] += x;
            k += k & -k;
        }
    }
    // for (auto i : tree) cout << i << ' ';
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            b -= (sum(a) - sum(a-1));
            while (a <= n) {
        	    tree[a] += b;
                a += a & -a;
            }
        } else {
            cout << sum(b) - sum(a-1) << '\n';
        }
    }
    
    return 0;
}