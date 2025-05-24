#include <bits/stdc++.h>
#define int long long
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> arr;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), comp);
    priority_queue<int> tasks;
    int j = 0, sum = 0;
    for (int i = arr[0].first; i >= 1; i--) {
        while (arr[j].first == i && j < n) {
            tasks.push(arr[j].second);
            j++;
        }
        if (!tasks.empty()) {
            sum += tasks.top();
            tasks.pop();
        }
    }
    cout << sum << "\n";
    return 0;
}