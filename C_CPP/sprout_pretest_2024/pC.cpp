#include <bits/stdc++.h>
using namespace std;

string rmspace(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') res = res + s[i];
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    string s;
    cin >> s;
    cin >> q;
    string sin;
    string s1, s2;
    cin.ignore();
    while (q--) {
        getline(cin, sin);
        sin = rmspace(sin);
        int i = 0;
        for (; i < sin.size(); i++) {
            if (sin[i]=='-') break;
        }
        s1 = sin.substr(0, i);
        s2 = sin.substr(i+2);
        size_t pos = s.find(s1);
        if (pos != string::npos) {
            s.replace(s.find(s1), s1.size(), s2);
        }
    }
    cout << s << endl;
    return 0;
}
