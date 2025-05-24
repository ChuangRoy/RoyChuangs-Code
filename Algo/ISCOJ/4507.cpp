#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    long long sum = 0;
    for (int i = 0 ; i < n / 2; i++) sum += a[i];
    cout << sum << endl;
    return 0;
}