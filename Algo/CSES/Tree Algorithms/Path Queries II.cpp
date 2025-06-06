#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ALL(x) begin(x),end(x)
#define eb emplace_back

typedef long long lli;

using namespace std;

const int nodes_cnt_max = 200005;

vector<lli> zkw_over_arr(nodes_cnt_max);
vector<lli> node_val(nodes_cnt_max);
vector<vector<int>> adj_list(nodes_cnt_max);

struct ZKW {
    vector<lli> t = vector<lli> (nodes_cnt_max * 2);
    int N;

    void init(int arr_size) {
        N = arr_size;
        for (int i = 0; i <= 2 * N + 1; i++) t[i] = 0;
    }

    void printdbg() {
        cerr << "You are trying to print something" << endl;
        int l = N, r = 2 * N - 1;
        while (l <= r) {
            for (int i = l; i <= r; i++) cerr << t[i] << ' ';
            cerr << endl;
            if (l % 2 == 1) l++;
            if (r % 2 == 0) r--;
            l /= 2;
            r /= 2;
        }
    }
    
    void build() {
        for (int i = N; i < 2 * N; i++) {
            t[i] = zkw_over_arr[i - N];
        }
        for (int i = N - 1; i >= 1; i--) {
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
    }
    
    void modify(int idx, lli val) {
        zkw_over_arr[idx] = val;
        idx += N;
        t[idx] = val;
        idx /= 2;
        while (idx >= 1) {
            t[idx] = max(t[2 * idx], t[2 * idx + 1]);
            idx /= 2;
        }
    }
    
    lli query(int l, int r) {
        l += N;
        r += N;
        lli res = -1;
        while (l <= r) {
            if (l % 2 == 1) res = max(t[l++], res);
            if (r % 2 == 0) res = max(t[r--], res);
            l /= 2;
            r /= 2;
        }
        return res;
    }
} zkw;

struct TREE {
    int N;
    vector<int> heavy_child = vector<int> (nodes_cnt_max), father_node = vector<int> (nodes_cnt_max), subtree_size = vector<int> (nodes_cnt_max),
        node_depth_from_top = vector<int> (nodes_cnt_max, 0), chain_top = vector<int> (nodes_cnt_max), dfs_order = vector<int> (nodes_cnt_max);
    int dfs_timer = 0;

    void dfs(int cur, int parent) {
        subtree_size[cur] = 1;
        heavy_child[cur] = -1;
        for (int nxt : adj_list[cur]) {
            if (nxt == parent) continue;
            father_node[nxt] = cur;
            node_depth_from_top[nxt] = node_depth_from_top[cur] + 1;
            dfs(nxt, cur);
            subtree_size[cur] += subtree_size[nxt];
            if (heavy_child[cur] == -1 || subtree_size[heavy_child[cur]] < subtree_size[nxt])
                heavy_child[cur] = nxt;
        }
    }
    
    void link_chains(int cur, int top) {
        chain_top[cur] = top;
        dfs_order[cur] = dfs_timer++;
        zkw_over_arr[dfs_order[cur]] = node_val[cur];
        if (heavy_child[cur] != -1) link_chains(heavy_child[cur], top);
        for (int nxt : adj_list[cur]) {
            if (nxt == father_node[cur] || nxt == heavy_child[cur]) continue;
            link_chains(nxt, nxt);
        }
    }

    lli jumping_query(int a, int b) {
        lli result = -1;
        while (chain_top[a] != chain_top[b]) {
            if (node_depth_from_top[chain_top[b]] > node_depth_from_top[chain_top[a]]) swap(a, b);
            result = max(zkw.query(dfs_order[chain_top[a]], dfs_order[a]) , result);
            a = father_node[chain_top[a]];
        }
        if (dfs_order[a] > dfs_order[b]) swap(a, b);
        result = max(zkw.query(dfs_order[a], dfs_order[b]), result);
        return result;
    }

    void modify(int node, lli val) {
        node_val[node] = val;
        zkw.modify(dfs_order[node], val);
    }

    void build() {
        dfs(1, 1);
        link_chains(1, 1);
    }
} tree;

void solve() {
    int N, Q;
    cin >> N >> Q;
    zkw.init(N);
    for (int i = 1; i <= N; i++) cin >> node_val[i];
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].eb(b);
        adj_list[b].eb(a);
    }
    tree.build();
    zkw.build();
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        // zkw.printdbg();
        if (a == 1) {
            tree.modify(b, c);
        }
        if (a == 2) {
            cout << tree.jumping_query(b, c) << ' ';
        }
    }
}

int main () {
    fastio;
    solve();
    return 0;
}