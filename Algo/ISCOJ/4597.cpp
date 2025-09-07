#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,long>a, pair<string,long>b) {
    return a.second > b.second;
}

int main () {
    int m;
    cin >> m;
    pair<string, long> pa[m];
    for (int i = 0; i < m; i++){
        cin >> pa[i].first;
        cin >> pa[i].second;
    }
    sort(pa, pa+m, cmp);
    cout << pa[0].first << " " << pa[1].first << endl;
    return 0;
}