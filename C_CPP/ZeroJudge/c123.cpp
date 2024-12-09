#include <iostream>
#include <vector>
using namespace std;

int main () {
    int m, n;
    vector<int> Station, Out;
    cin >> n;
    int i, target;
    while (n) {
        cin >> m;
        while (m) { // Main Period
            // Input
            Out.clear();
            Station.clear();
            Out.push_back(m);
            for (i = 0; i < n-1; i++) {
                cin >> m;
                Out.insert(Out.begin(), m);
            }
            // Logic
            i = 1; // In Way
            bool ok = 1;
            while ((!Out.empty()) && ok) {
                target = Out.back();
                while (i < target) {
                    Station.push_back(i);
                    i++;
                }
                if (i == target) {
                    Out.pop_back();
                    i++;
                } else {
                    if (Station.back() == target) {
                        Station.pop_back();
                        Out.pop_back();
                    } else {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            cin >> m;
        }
        cin >> n;
    }
    return 0;
}
