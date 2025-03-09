#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    queue<int> q;
    while (n--) {
        int op;
        cin >> op;
        switch (op) {
        case 1:
            int value; cin >> value;
            q.push(value);
            break;
        case 2:
            if (q.empty()) {
                cout << "empty!\n";
                break;
            }
            int top = q.front();
            q.pop();
            cout << top << '\n';
            break;
        }
    }
}