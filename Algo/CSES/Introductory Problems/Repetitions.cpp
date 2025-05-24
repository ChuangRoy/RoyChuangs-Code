#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int currLen = 1, maxLen = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            currLen++;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }
    cout << maxLen << endl;
    return 0;
}