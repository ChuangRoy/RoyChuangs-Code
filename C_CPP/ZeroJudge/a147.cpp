#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++) {
            if (i%7)
                cout << i << " ";
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
