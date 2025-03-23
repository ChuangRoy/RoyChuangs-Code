#include <bits/stdc++.h>
using namespace std;

const int arr_size = 2e5;
int a[arr_size];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    q.push_back(a[0]);
    int lastIndex = 0;
    for (int i = 1; i < n; i++) {
        if (q[lastIndex] <= a[i]) {
            q.push_back(a[i]);
            lastIndex++;
        } else {
            auto replace = upper_bound(q.begin(), q.end(), a[i]);
            *replace = a[i];
        }
    }
    cout << lastIndex + 1 << '\n';
    return 0;
}