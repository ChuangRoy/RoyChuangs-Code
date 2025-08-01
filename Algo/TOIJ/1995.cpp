#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#define pii pair<int, int>
#define pll pair<lli, lli>

using namespace std;
typedef long long int lli;

int tree[5000006];
int N;

struct ZKW {
    void build() {
        for (int i = N - 1; i > 0; --i) {
            tree[i] = max(tree[i<<1], tree[(i<<1)|1]);
        }
    }
    
    int query(int l, int r) {
        l += N;
        r += N;
        int res = 0;
        while (l <= r) {
            if (l & 1) {
                res = max(tree[l], res);
                ++l;
            }
            if (~r & 1) {
                res = max(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
} zkw;

void solve() {
    int M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        scanf("%d", &x);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[N + i]);
    }
    zkw.build();
    rewind(stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        a--;
        b--;
        // printf("%d %d\n", a, b);
        printf("%d\n", zkw.query(a, b));
    }
}

int main() {
    solve();
    return 0;
}