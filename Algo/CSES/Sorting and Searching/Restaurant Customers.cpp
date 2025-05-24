#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a, b;
    set<int> idx;
    map<int, int> m;
    while (n--) {
        cin >> a >> b;
        m[a] = m[a] + 1;
        m[b+1] = m[b+1] - 1;
        idx.insert(a);
        idx.insert(b+1);
    }
    int sum = 0;
    int maxSum = 0;
    for (auto i: idx) {
        sum += m[i];
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << '\n';
    return 0;
}