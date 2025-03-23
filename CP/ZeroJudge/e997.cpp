#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string line;
    getline(cin, line);
    stringstream ss(line);
    string name;
    vector<string> names;
    while (ss >> name) {
        names.push_back(name);
    }
    int n; cin >> n;
    cout << names[names.size() - n] << '\n';
    return 0;
}