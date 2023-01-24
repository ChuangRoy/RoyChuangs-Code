#include <iostream>
using namespace std;

int main () {
    char a[14][2];
    char input[2];
    int aa = 0;
    for (int i = 1; i < 14; i++) {
        cin >> input;
        if (input[0] == '0')
            a[i][0] = '5';
        else
            a[i][0] = input[0];
        a[i][1] = input[1];
        cout << a[i][0] << a[i][1] << " ";
    }
    // for(int last_index = 0; last_index < 12; last_index++) { //sort
        // for (int target_index = last_index + 1; target_index > 0; target_index--) { // comparing from last index to 0
            // if (a[target_index][0] < a[target_index-1][0]) {
                // int temp = a[target_index-1][0];
                // a[target_index-1][0] = a[target_index][0];
                // a[target_index] = temp;
                // temp = a[target_index-1][1];
                // a[target_index-1][1] = a[target_index][1];
                // a[target_index] = temp;
            // }
        // }
    // }
    for (int i = 1; i < 14; i++) {
        int n = 0;
        int j = i+1;
        if (a[i][0] == '_')
            j = 15;
        for (; j < 14; j++) {
            if (a[i][0] == a[j][0]&&a[i][1] == a[j][1]) {
                cout << i << " " << a[i][0] << a[i][1] << " " << a[j][0] << a[j][1] << endl;
                a[j][0] = '_';
                n = 1;
            }
        }
        aa += n;
    }
    cout << 6 - aa;
    return 0;
}
