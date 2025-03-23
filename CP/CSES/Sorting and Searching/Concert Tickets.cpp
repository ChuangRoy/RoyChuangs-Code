// by chatgpt

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    int t;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h.insert(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            h.erase(it);
        }   
    }
    return 0;
}