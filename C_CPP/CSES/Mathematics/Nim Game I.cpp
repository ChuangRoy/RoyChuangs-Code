#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >>n;
        int x; cin >> x;
        int xor_x = x;
        while (--n) {
            cin >> x;
            xor_x = xor_x ^ x;
        }
        if (xor_x)
            cout << "first" << "\n";
        else
            cout << "second" << "\n";
    return 0;
}
