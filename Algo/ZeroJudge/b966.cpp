#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
short arr[N] = {0};

int main () {
    int k;
    cin >> k;
    int l, r;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        arr[l] += 1;
        arr[r] -= 1;
    }
    long long sum = 0;
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > 0) cnt++;
    }
    cout << cnt;
    return 0;
}