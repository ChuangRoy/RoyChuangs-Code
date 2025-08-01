#pragma GCC optimize("Ofast")
#include <iostream>
#include <set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long lli;

int N, window_size;

// median = *smaller_st.rbegin()
multiset<int> bigger_st;
multiset<int> smaller_st;

void make_balance() {
    while (SZ(smaller_st) > (window_size + 1) / 2) {
        bigger_st.insert(*smaller_st.rbegin());
        smaller_st.erase(--smaller_st.end());
    }
    while (SZ(bigger_st) > window_size / 2) {
        smaller_st.insert(*bigger_st.begin());
        bigger_st.erase(bigger_st.begin());
    }
}

int get_median() {
    make_balance();
    return *smaller_st.rbegin();
}

void insert_value(int val) {
    int median = get_median();
    if (val <= median) {
        smaller_st.insert(val);
    } else {
        bigger_st.insert(val);
    }
    make_balance();
    // for (auto x : smaller_st) cerr << x << ' ';
    // cerr << ' ';
    // for (auto x : bigger_st) cerr << x << ' ';
    // cerr << endl;
}

void erase_value(int val) {
    if (bigger_st.find(val) != bigger_st.end()) {
        bigger_st.erase(bigger_st.find(val));
    } else {
        smaller_st.erase(smaller_st.find(val));
    }
    make_balance();
}

void solve() {
    cin >> N >> window_size;
    vector<int> arr(N);
    for (auto &x : arr) cin >> x;
    smaller_st.insert(arr[0]);
    for (int i = 1; i < window_size; i++) {
        insert_value(arr[i]);
    }
    cout << get_median() << ' ';
    for (int i = window_size; i < N; i++) {
        insert_value(arr[i]);
        erase_value(arr[i - window_size]);
        cout << get_median() << ' ';
    }
}

int main() {
    fastio;
    solve();
    return 0;
}