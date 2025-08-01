#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long lli;

const lli inf = 1e18;

struct Node {
    lli M, L, R, S;
    
    void set_value_for_single_node(lli val) {
        M = max(0LL, val);
        L = val;
        R = val;
        S = val;
    }

    void set_void_node() {
        M = -inf;
        L = -inf;
        R = -inf;
        S = 0;
    }
    
    Node operator+ (Node r) {
        Node ret;
        ret.M = max({M, r.M, R + r.L});
        ret.L = max(L, S + r.L);
        ret.R = max(R + r.S, r.R);
        ret.S = S + r.S;
        return ret;
    }
};

const int maxN = 2e5;
int arr[maxN + 5];

struct ZKW {
    Node tree[200005];
    int N = 0;

    void printdbg() {
        int l = N, r = 2 * N - 1;
        while (l <= r) {
            for (int i = l; i <= r; i++) cerr << '(' << tree[i].R << ')' << ' ';
            cerr << endl;
            if (l % 2 == 1) l++;
            if (r % 2 == 0) r--;
            l /= 2;
            r /= 2;
        }
    }
    
    void init(int n) {
        N = n;
        // for (int i = 0; i < 2 * N; i++) {
        //     tree[i].set_value_for_single_node(-inf);
        // }
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
        resL.set_void_node();
        resR.set_void_node();
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
        return (resL + resR).M;
    }
} zkw;

void solve () {
    int n, q;
    cin >> n >> q;
    zkw.init(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    zkw.build();
    while (q--) {
        // zkw.printdbg();
        int a, b;
        cin >> a >> b;
        cout << zkw.query(a-1, b-1) << '\n';
    }
}

int main () {
    AC
    solve();
    return 0;
}