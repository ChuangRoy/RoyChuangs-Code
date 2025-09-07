#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int q; cin >> q;
    deque<int> dq;
    while (q--) {
        int op, val;
        cin >> op >> val;
        if (op == 1) {
            auto it = upper_bound(ALL(dq), val);
            if (it == dq.end()) dq.push_back(val);
            else dq.insert(it, val);
        } else {
            if (val == 0) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
    }
    return 0;
}