#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    unsigned int i = n*n/2;
    char a[n][n];
    string input;
    for (int j = 0; j < n; j++) {
        cin >> input;
        for (int k = 0; k < n; k++) {
            a[j][k] = input[k];
        }
    }
    return 0;
}