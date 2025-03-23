#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1e6;
int a[arr_size];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mid = n/2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (k - abs(a[i] - a[mid]) * p);
    }
    cout << sum << '\n';
    return 0;
}