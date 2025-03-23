#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> pre(2000);

void travel (int l, int r) {
    if (r < l) return;
    int target = pre[l];
    int i = l+1;
    while (i <= r && pre[i] < target) {
        i++;
    }
    travel(l + 1, i - 1);
    travel(i, r);
    cout << target << '\n';
}

int main () {
    AC
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    travel(0, n - 1);
    return 0;
}