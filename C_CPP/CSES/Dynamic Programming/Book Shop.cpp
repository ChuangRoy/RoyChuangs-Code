#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1e5 + 1;
int prices[1000];
int pages[1000];
int rec [arr_size];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    for (int i = 0; i < arr_size; i++) rec[i] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            rec[j] = max(rec[j], rec[j-prices[i]] + pages[i]);
        }
    }
    cout << rec[x];
    return 0;
}