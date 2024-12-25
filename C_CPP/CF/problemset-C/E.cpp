#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int x, n;
    cin >> x >> n;
    priority_queue <long long, vector<long long>, greater<long long>> a;
    int d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        a.push(d);
    }
    long long sum = 0;
    while (a.size() > 1) {
        long long l, r;
        l = a.top();a.pop();
        r = a.top();a.pop();
        sum += (l + r);
        a.push(l + r);
    }
    cout << sum << endl;
    return 0;
}
