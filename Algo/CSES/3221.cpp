#pragma GCC optimize("Ofast")
#include <iostream>
#include <deque>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define pii pair<int, int>

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
    deque<pii> dq;
    dq.eb(arr[0], 0);
    for (int i = 1; i < K; i++) {
        while (!dq.empty() && dq[0].first >= arr[i]) dq.pop_front();
        while (!dq.empty() && dq.end() [-1].first >= arr[i]) dq.pop_back();
        dq.eb(arr[i], i);
    }
    lli ans = 0;
    ans ^= dq[0].first;
    for (int i = K; i < N; i++) {
        if (dq[0].second <= i - K) dq.pop_front();
        while (!dq.empty() && dq[0].first >= arr[i]) dq.pop_front();
        while (!dq.empty() && dq.end()[-1].first >= arr[i]) dq.pop_back();
        dq.eb(arr[i], i);
        ans ^= dq[0].first;
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}