#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long int lli;

int arr[200005];

int lowbit(int x) {
    return x & -x;
}

struct Node {
    lli prefix, sum;
    
    void set_value_for_single_node(int val) {
        sum = val;
        prefix = max(0, val);
    }
    
    Node operator+ (Node r) {
        Node res;
        res.prefix = max(sum + r.prefix, prefix);
        res.sum = sum + r.sum;
        return res;
    }
};

struct ZKW {
    Node tree[400005];
    int N = 0;
    
    void printdbg() {
        int l = N, r = 2 * N - 1;
        while (l <= r) {
            for (int i = l; i <= r; i++) cerr << '(' << tree[i].prefix << ", " << tree[i].sum << ')' << ' ';
            cerr << endl;
            if (l % 2 == 1) l++;
            if (r % 2 == 0) r--;
            l /= 2;
            r /= 2;
        }
    }
    
    void init(int n) {
        N = n;
        for (int i = 0; i < 2 * N; i++) {
            tree[i].set_value_for_single_node(0);
        }
    }
    
    void build() {
        for (int i = 0; i < N; i++) {
            tree[N + i].set_value_for_single_node(arr[i]);
        }
        for (int i = N - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void modify(int idx, int val) {
        idx += N;
        tree[idx].set_value_for_single_node(val);
        idx /= 2;
        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }
    
    lli query(int l, int r) {
        l += N;
        r += N;
        Node resL, resR;
        resL.set_value_for_single_node(0);
        resR.set_value_for_single_node(0);
        while (l <= r) {
            if (l % 2 == 1) {
                resL = resL + tree[l];
                l++;
            }
            if (r % 2 == 0) {
                resR = tree[r] + resR;
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return (resL + resR).prefix;
    }
} zkw;

void solve() {
    int n, q;
    cin >> n >> q;
    zkw.init(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    zkw.build();
    // zkw.printdbg();
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int k, u;
            cin >> k >> u;
            zkw.modify(k-1, u);
        }
        if (op == 2) {
            int a, b;
            cin >> a >> b;
            cout << zkw.query(a-1, b-1) << '\n';
        }
    }
}

int main() {
    fastio;
    solve();
    return 0;
}