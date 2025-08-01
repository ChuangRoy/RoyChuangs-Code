#include <bits/stdc++.h>
using namespace std;

const int arr_size = 2e5;
int x[arr_size];
unsigned long long pre_sum[arr_size+1] = {0};

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
        pre_sum[i+1] = sum;
    }
    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << pre_sum[b] - pre_sum[a-1] << '\n';
    }
    return 0;
}