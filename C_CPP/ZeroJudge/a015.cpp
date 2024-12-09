#include <iostream>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int array [a][b];
    int input;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> array[i][j];
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
