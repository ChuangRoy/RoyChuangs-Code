#include <bits/stdc++.h>
using namespace std;

int arr[100];
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        int blocks = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        bool closed = 1;
        for (int i = 0; i < n && blocks < 2; i++) {
            if (arr[i] == 0 && !closed) closed = 1;
            if (arr[i] != 0 && closed) {
                blocks++;
                closed = 0;
            }
        }
        cout << blocks << "\n";
    }
    return 0;
}