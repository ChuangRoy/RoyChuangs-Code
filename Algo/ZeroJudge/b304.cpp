/*
Test Case:
3
([])
(([()])))
([()[]()])()
*/

#include <iostream>
#include <stack>

using namespace std;

int main () {
    bool ok = 1;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        ok = 1;
        string a;
        // cin >> a;
        getline(cin, a);
        stack<bool> st;
        for (int j = 0; j < a.length(); j++) {
            switch (a[j]) {
                case '(':
                    st.push(0);
                    break;
                case '[':
                    st.push(1);
                    break;
                case ')':
                    if (!st.empty()) {
                        if (st.top() == 0) {
                            st.pop();
                            ok = 1;
                        } else {
                            ok = 0;
                            j = a.length();
                        }
                    } else {
                        ok = 0;
                        j = a.length();
                    }
                    break;
                case ']':
                    if (!st.empty()) {
                        if (st.top() == 1) {
                            st.pop();
                            ok = 1;
                        } else {
                            ok = 0;
                            j = a.length();
                        }
                    } else {
                        ok = 0;
                        j = a.length();
                    }
                    break;
            }
        }
        if (ok && st.empty()) {
                cout << "Yes";
        } else {
                cout << "No";
        }
        cout << endl;
    }
    return 0;
}