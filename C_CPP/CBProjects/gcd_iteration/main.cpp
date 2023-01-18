#include <iostream>
using namespace std;

int main () {
    int m, n;
    cin >> m >> n;
    while (m % n != 0) {
        int temp = m;
        m = n;
        n = temp % n;
    }
    cout << n << endl;
    return 0;
}