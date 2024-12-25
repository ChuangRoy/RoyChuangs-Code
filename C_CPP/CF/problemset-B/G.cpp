#include <bits/stdc++.h>
using namespace std;

int rec[1000000];
int remain[2024];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        long long cnt = 0;
        for (int i = 0; i < 2024; i++) remain[i] = 0;
        int k = s.length() - 1;
        rec[0] = s[k] - '0';
        remain[rec[0]]++;
        if (rec[0] == 0) cnt++;
        int times = 1;
        for (int i = 1; i <= k; i++) {
            int input = s[k-i] - '0';
            times = times * 10 % 2024;
            rec[i] = (long long) (rec[i-1] + times * input) % 2024;
            remain[rec[i]]++;
            if (rec[i] == 0) cnt += remain[0];
            else if (remain[rec[i]] >= 2) cnt += (remain[rec[i]] - 1);
        }
        cout << cnt << endl;
    }
    return 0;
}