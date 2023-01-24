#include <iostream>
using namespace std;

int main () {
    long int a;
    cin >> a;
    for (int i = 0; i <= a; i++) {
        if ((a-i) <= 1000) {
            cout << i << " " << a-i << endl;
            break;
        }
    }
    return 0;
}
