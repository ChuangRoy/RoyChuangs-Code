#pragma GCC optimize("Ofast")
#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>
using namespace std;

vector<long long> a(1000);
vector<long long> record(1000);

bool can_swap(int a, int b) {
    string s;
    cout << "? " << a << ' ' << b << endl;
    cin >> s;
    return s == "NO";
}

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    // merge a b
    int la = l, lb = mid + 1, i = l;
    while (la <= mid && lb <= r) {
        if (can_swap(a[la], a[lb])) {
            record[i] = a[lb];
            lb++;
            i++;
        }
        else {
            record[i] = a[la];
            la++;
            i++;
        }
    }
    bool flag = 0;
    if (la > mid) flag = 1;
    while (i <= r) {
        if (flag) {
            record[i] = a[lb];
            lb++;
            i++;
        }
        else {
            record[i] = a[la];
            la++;
            i++;
        }
    }
    for (int j = l; j <= r; j++) a[j] = record[j];
}

void solve() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) a[i-1] = i;
    merge_sort(0, N-1);
    
    // for (int i = 0; i < N; i++) cout << a[i] << ' ';
    vector<pair<int, int>> ans(N);
    for (int i = 0; i < N; i++) ans[i] = {a[i], i+1};
    sort(ans.begin(), ans.end());
    cout << "! ";
    for (auto [_, k] : ans) cout << k << ' ';
    cout << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}