#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long x;
    cin >> x;
    long long maxSum = x, currSum = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        currSum = max(currSum + x, x);
        maxSum = max(currSum, maxSum);
    }
    cout << maxSum << '\n';
    return 0;
}