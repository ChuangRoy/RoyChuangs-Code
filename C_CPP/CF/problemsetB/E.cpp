#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    int m, n;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<long> h;
        long hi, ti;
        while (n--) {
            cin >> hi;
            h.push_back(hi);
        }
        sort(h.begin(), h.end());
        // int L, R;
        while (m--) {
            cin >> ti;
            int i = 0;
            int h_size = h.size();
            while (h[i] <= ti && i < h_size) i++;
            if (i < 1)
            	cout << -1 << endl;
            else {
            	cout << h[i-1] << endl;
            	h.erase(h.begin()+i-1);
            }
            // L = 0; R = h.size() - 1;
            // while (L < R) {
                // if (h[(L+R)/2] > ti)
                    // R = (L+R) / 2 - 1;
                // else if (h[(L+R)/2] < ti)
                    // L = (L+R) / 2 + 1;
                // else {
                    // L = (L+R) / 2;
                    // R = (L+R) / 2;
                // }
            // }
            // if (h[R] > ti) {
                // if (R - 1 >= 0) {
                    // cout << h[R - 1] << endl;
                    // h.erase(h.begin() + R - 1);
                // }
                // else
                    // cout << "-1" << endl;
            // }else{
                // cout << h[R] << endl;
                // h.erase(h.begin() + R);
            // }
        }
    }
    return 0;
}