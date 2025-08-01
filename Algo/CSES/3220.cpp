#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back

using namespace std;
typedef long long lli;

void solve() {
    int N, K;
    cin >> N >> K;
    lli x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<lli> arr(N);
    arr[0] = x;
    for (int i = 1; i < N; i++) arr[i] = (a * arr[i-1] + b) % c;
    lli sum = 0, ans = 0;
    for (int i = 0; i < K; i++) {
        sum += arr[i];
    }
    ans ^= sum;
    for (int i = K; i < N; i++) {
        sum -= arr[i - K];
        sum += arr[i];
        ans ^= sum;
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}