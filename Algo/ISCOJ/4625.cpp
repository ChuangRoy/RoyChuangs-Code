#include <iostream>
using namespace std;

int ans[32];

int main() {
    int A;
    cin >> A;
    if (A == 0) {
        cout << 0 << endl;
    } else {
        int A_copy = A;
        int number_length = 0;
        while (A_copy > 0) {
            number_length = number_length + 1;
            A_copy = A_copy / 2;
        }

        for (int i = 0; i < number_length; i++) {
            ans[i] = A % 2;
            A = A / 2;
        }

        for (int i = number_length - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}