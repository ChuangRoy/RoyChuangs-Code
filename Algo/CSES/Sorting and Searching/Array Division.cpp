#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

bool check (vector<int> &arr, int n, int k, ll x) {
    int t = 0, i = -1;
    while (t < k && i < n - 1) {
        ll sum = 0;
        while (i < n - 1 && sum + arr[i+1] <= x) {
            i++;
            sum += arr[i];
        }
        t++;
    }
    if (i < n - 1) {
        return 0;
    } else {
        return 1;
    }
}

void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll l = 1, r = sum;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(arr, n, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

int main () {
    AC
    solve();
    return 0;
}