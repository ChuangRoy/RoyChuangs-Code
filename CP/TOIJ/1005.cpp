#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int N;

void solve () {
    vector<int> nums;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        for (auto n : nums) {
            if (__gcd(n, k) == 1) cnt++;
        }
        nums.push_back(k);
    }
    if (cnt == 0) {
        cout << "No estimate for this data set.\n";
        return;
    }
    cout << fixed << setprecision(6) << sqrt(3.0*N*(N-1)/cnt) << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N) {
        solve();
        cin >> N;
    }
	return 0;
}
