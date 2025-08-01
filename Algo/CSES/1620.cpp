#include <bits/stdc++.h>
using namespace std;
#define int long long

const int arr_size = 2e5;
int k[arr_size];

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, quantity;
    cin >> n >> quantity;
    for (int i = 0; i < n; i++) cin >> k[i];
    
    long long l = 0, r = 1e18;
    unsigned long long mid, sum;
    while (l < r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mid / k[i];
            if (sum > quantity) break;
        }

        if (sum >= quantity) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}