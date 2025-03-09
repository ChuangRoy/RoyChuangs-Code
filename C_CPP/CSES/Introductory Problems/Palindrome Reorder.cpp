#include <bits/stdc++.h>

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

signed main ()
{
    AC
    string s;
    cin >> s;
    int n = s.size();
    vector<int> rec(26, 0);
    for (auto it : s) {
        rec[it-'A']++;
    }
    int odd = 0;
    int odd_idx;
    int diff = 0;
    for (int i = 0; i < 26; i++) {
        // cout << rec[i] << ' ';
        if (rec[i] % 2) {
            odd++;
            diff++;
            odd_idx = i;
        }
    }
    // cout << '\n';
    if (odd > 1 || ((odd ^ n%2) && diff <= 1)) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (odd == 1) {
        for (int i = 0; i < 26; i++) {
            if (i == odd_idx) continue;
            for (int j = 0; j < rec[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
        for (int j = 0; j < rec[odd_idx]; j++) {
            cout << char(odd_idx + 'A');
        }
        for (int i = 25; i >= 0; i--) {
            if (i == odd_idx) continue;
            for (int j = 0; j < rec[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < rec[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < rec[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
    }
    return 0;
}