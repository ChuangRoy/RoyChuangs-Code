#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define SZ(x) ((int) x.size())

using namespace std;

vector<vector<int>> rec(1e3+1);

vector<int> getSeq (int n) {
    if (n == 1) return {1};
    if (n <= 1e3 && !rec[n].empty()) return rec[n];
    int half = n / 2;
    auto evenSeq = getSeq(half);
    vector<int> oddSeq;
    if (n % 2)
        oddSeq = getSeq(n - half);
    else
        oddSeq = evenSeq;
    if (n <= 1e3) {
        for (auto i : oddSeq)
            rec[n].push_back(2*i - 1);
        for (auto i : evenSeq)
            rec[n].push_back(2*i);
        return rec[n];
    } else {
        vector<int> res;
        for (auto i : oddSeq)
            res.push_back(2*i - 1);
        for (auto i : evenSeq)
            res.push_back(2*i);
        return res;
    }
}

void solve () {
    int N; cin >> N;
    auto ans = getSeq(N);
    for (auto it : ans) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
