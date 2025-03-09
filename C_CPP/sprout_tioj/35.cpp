#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    stack<int> st;
    while (n--) {
        int op;
        cin >> op;
        switch (op) {
        case 1:
            int value; cin >> value;
            st.push(value);
            break;
        case 2:
            if (st.empty()) {
                cout << "empty!\n";
                break;
            }
            int top = st.top();
            st.pop();
            cout << top << '\n';
            break;
        }
    }
}