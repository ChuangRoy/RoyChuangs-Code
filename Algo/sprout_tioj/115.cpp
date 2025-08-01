#pragma GCC optimize("Ofast")
#include <iostream>

using namespace std;

const int mod = 1e7+19;
int arr[1000005], temp[1000005];

long long ans = 0;

void msort (int start, int end) {
    if (start == end) return;
    int m = (start + end) / 2;
    msort(start, m);
    msort(m+1, end);
    int l = start, r = m + 1;
    int it = l;
    long long cnt = 0;
    long long sum = 0;
    while (l <= m && r <= end) {
        if (arr[r] < arr[l]) {
            sum += arr[r];
            temp[it++] = arr[r++];
            cnt++;
        } else {
            ans += (cnt*arr[l] + sum);
            temp[it++] = arr[l++];
            if (ans >= mod)
                ans %= mod;
        }
    }
    while (r <= end) {
        temp[it++] = arr[r++];
    }
    while (l <= m) {
        ans += (cnt*arr[l] + sum);
        temp[it++] = arr[l++];
        if (ans >= mod)
            ans %= mod;
    }
    for (int i = start; i <= end; i++)
        arr[i] = temp[i];
}

void solve () {
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    msort(0, N - 1);
    cout << ans % mod << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
