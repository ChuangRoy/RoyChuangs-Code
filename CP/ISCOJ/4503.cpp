#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int a_arr[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
        cin >> a_arr[i];
    int i, j;
    cin.ignore();
    while (m--) {
        cin >> i >> j;
        int temp = a_arr[i];
        a_arr[i] = a_arr[j];
        a_arr[j] = temp;
    }
    int k;
    while (q--) {
        cin >> k;
        cout << a_arr[k] << endl;
    }

    return 0;
}