#pragma GCC optimize("Ofast")
#include <iostream>
#include <map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back

using namespace std;
typedef long long lli;

map<int, int> freq;
int cnt = 0;

void add_num(int val) {
    if (freq[val] == 0) cnt++;
    freq[val]++;
}

void remove_num(int val) {
    freq[val]--;
    if (freq[val] == 0) cnt--;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<lli> arr(N);
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        add_num(arr[i]);
    }
    cout << cnt << ' ';
    for (int i = K; i < N; i++) {
        cin >> arr[i];
        add_num(arr[i]);
        remove_num(arr[i - K]);
        cout << cnt << ' ';
    }
    cout << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}