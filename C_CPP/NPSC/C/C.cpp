#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main () {
    int l = 0, h = 1000;
    string a;
    for(int i = 0; i < 10; i++) {
        cout << (l+h)/2 << endl;
        fflush(stdin);
        cin >> a;
        if (a == "correct")
            break;
        else if (a == "higher")
            h = (l+h)/2;
        else if (a == "lower")
            l = (l+h)/2;
    }
    return 0;
}
