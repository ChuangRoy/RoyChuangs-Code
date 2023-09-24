#include <iostream>
using namespace std;

int main () {
    int n;
    while(cin >> n) {
        if (n%4==0&&(n%100||n%400==0))
            cout << "閏年" << endl;
        else
            cout << "平年" << endl;
    }
    return 0;
}
