#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void writeValue (vector<int> &tree, int treeSize, int n) {
    int cur = treeSize;
    tree[cur] = n;
    int nxt = cur / 2;
    while (nxt >= 1 && tree[nxt] > tree[cur]) {
        swap(tree[nxt], tree[cur]);
        nxt >>= 1;
        cur >>= 1;
    }
}

int popValue (vector<int> &tree, int &treeSize) {
    int ret = tree[1];
    tree[1] = tree[treeSize];
    treeSize--;
    int cur = 1;
    while (cur * 2 <= treeSize) {
        int smallest = cur;
        if (tree[smallest] > tree[cur * 2]) {
            smallest = cur * 2;
        }
        if (cur * 2 < treeSize && tree[smallest] > tree[cur * 2 + 1]){
            smallest = cur * 2 + 1;
        }
        if (smallest == cur) break;
        swap(tree[cur], tree[smallest]);
        cur = smallest;
    }
    return ret;
}

signed main () {
    AC
    int t; cin >> t;
    vector<int> tree(1e6+1, 0);
    int treeSize = 0;
    while (t--) {
        int op; cin >> op;
        if (op == 1) {
            int n; cin >> n;
            treeSize++;
            writeValue(tree, treeSize, n);
        } else {
            if (treeSize == 0) {
                cout << "Empty !\n";
            } else {
                cout << popValue(tree, treeSize) << '\n';
            }
        }
    }
    return 0;
}