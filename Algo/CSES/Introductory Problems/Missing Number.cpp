#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a;
    vector<bool> rec(n, 1);
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        rec[a-1] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (rec[i]) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}