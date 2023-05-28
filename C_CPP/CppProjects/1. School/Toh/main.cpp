#include <iostream>
using namespace std;

int counter = 1;

void Toh (int n, char a, char b, char c) {
    if (n == 1) {
        cout << counter << ". Disk " << n << " from " << a << " to " << c << endl;
    counter += 1;
    }
    else {
        Toh(n - 1, a, c, b);
        cout << counter << ". Disk " << n << " from " << a << " to " << c << endl;
        counter += 1;
        Toh(n - 1, b, a, c);
    }
}

int main () {
    Toh(8, 'a', 'b', 'c');
    return 0;
}