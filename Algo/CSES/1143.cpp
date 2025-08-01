#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl

using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;

const int maxN = 2e5;
int N;
int tree[2*maxN + 5]; // maximums

void update (int idx, int x) {
    idx += N;
    tree[idx] = x;
    idx /= 2;
    while (idx >= 1) {
        tree[idx] = max(tree[2*idx], tree[2*idx+1]);
        idx /= 2;
    }
}

int query (int l, int r) {
    l += N; r += N;
    int ret = -inf;
    while (l <= r) {
        if (l % 2 == 1) ret = max(tree[l++], ret);
        if (r % 2 == 0) ret = max(tree[r--], ret);
        l /= 2; r /= 2;
    }
    return ret;
}

void processQuery () {
    int k; cin >> k;
    if (k > query(1, N)) {
        cout << 0 << ' ';
        return;
    }
    int l = 1, r = N;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (query(l, mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << ' ';
    update(l, query(l, l)-k);
}

void solve () {
    int m;
    cin >> N >> m;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while (m--) {
        processQuery();
    }
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}