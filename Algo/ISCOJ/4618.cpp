#include <bits/stdc++.h>
using namespace std;

const int arr_size = 2e5;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long a;
    int n; cin >> n;
    cin >> a;
    long long maxSum = a;
    long long currSum = maxSum;
    for (int i = 1; i < n; i++) {
        cin >> a;
        currSum += a;
        currSum = max(currSum, a);
        maxSum = max(maxSum, currSum);
    }
    cout << maxSum << '\n';
    return 0;
}