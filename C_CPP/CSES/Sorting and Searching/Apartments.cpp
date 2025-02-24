#include <bits/stdc++.h>
using namespace std;
 
const int arr_size = 2e5;
int a[arr_size], b[arr_size];
// a:size desired; b:apartment size
 
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int l = 0, r = 0;
    int cnt = 0;
    while (l < n && r < m) {
        if (b[r] + k < a[l]) {
            r++;
        }
        else if (b[r] - k > a[l]) {
            l++;
        }
        else {
            l++; r++;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}