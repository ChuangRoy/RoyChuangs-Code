#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int day = 0;
    int n; 
    while (cin >> n) {
        day++;
        cin.ignore();
        int t = 0;
        vector<pair<int, int>> rec;
        while (n--) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string s1, s2;
            ss >> s1 >> s2;
            // cout << s1 << ' ' << s2 << '\n';
            int t1 = (s1[1]-'0')*60+(s1[3]-'0')*10+(s1[4]-'0');
            int t2 = (s2[1]-'0')*60+(s2[3]-'0')*10+(s2[4]-'0');
            rec.push_back(make_pair(t, t1-t));
            t = t2;
        }
        rec.push_back(make_pair(t, 480-t));
        int maxt, maxt_length = 0;
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i].second > maxt_length) {
                maxt_length = rec[i].second;
                maxt = rec[i].first;
            }
        }
        cout << "Day #" << day << ": the longest nap starts at 1" << maxt / 60 << ':';
        if (maxt % 60 > 9) cout << maxt % 60;
        else cout << 0 << maxt % 60;
        cout << " and will last for ";
        if (maxt_length / 60 > 0) cout << (maxt_length / 60) << " hours and ";
        cout << maxt_length % 60;
        cout << " minutes. \n";
        // cout << maxt << ' ' << maxt_length << '\n';
        // cout << '\n';
    }
    return 0;
}