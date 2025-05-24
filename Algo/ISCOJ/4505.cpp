#pragma gcc optimize("Ofast")
#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    long long prevMin;
    cin >> prevMin;
    for (int i = 1; i <= N; i++) {
        long long num;
        cin >> num;
        if (num < prevMin) {
            cout << '(';
            if (i == 1)
                cout << 's';
            else
                cout << i-1;
            cout << ", ";
            cout << i << ")\n";
            prevMin = num;
        }
    }
    return 0;
}
