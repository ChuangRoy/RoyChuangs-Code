#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 10;

void modify(vector<int> &tree, int n, int k, int x) {
	k += n; // 先移到對應位置
    tree[k] = x;
    for (k /= 2; k > 0; k /= 2) {
    	tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

int getMin(vector<int> &tree, int n, int l, int r) {
	l += n, r += n;
    int ret = inf;
    while (l <= r) {
    	// 如果父節點會超出範圍就縮進來
    	if (l % 2 == 1) ret = min(tree[l++], ret);
        if (r % 2 == 0) ret = min(tree[r--], ret);
        l /= 2, r /= 2; // 移動到上一層
    }
    return ret;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> tree(2*n+10, inf);
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        modify(tree, n, i, x);
    }
    // for (auto i : tree) cout << i << ' ';
    // cout << '\n';
    int op, a, b;
    while (q--) {
        cin >> op >> a >> b;
        if (op == 1) {
            modify(tree, n, a, b);
        } else {
            cout << getMin(tree, n, a, b) << '\n';
        }
    }
    return 0;
}