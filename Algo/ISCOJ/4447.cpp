#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    long sum = 0;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        if (i % k) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}