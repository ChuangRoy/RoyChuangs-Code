#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> rec(26);
    for (int i = 0; i < 26; i++) rec[i] = make_pair(i, 0);
    string s;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (auto it : s) {
            if ('A' <= it && it <= 'Z')
                rec[it-'A'].second++;
            if ('a' <= it && it <= 'z')
                rec[it-'a'].second++;
        }
    }
    sort(rec.begin(), rec.end(), [](auto a, auto b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for (int i = 0; i < 26; i++) {
        if (rec[i].second)
            cout << char('A'+rec[i].first) << ' ' << rec[i].second << '\n';
    }
    return 0;
}