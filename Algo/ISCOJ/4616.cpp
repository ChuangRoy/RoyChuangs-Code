#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b;
    cin >> a >> b;
    int m, n;
    m = a[a.size()-1] - '0';
    n = b[b.size()-1] - '0';
    if ((m + n) % 2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}