#include <iostream>
#include <algorithm>
using namespace std;

// just sort???
int main () {
    int n;
    cin >> n;
    while (n) {
        unsigned int *data = new unsigned int[n];
        for (int i = 0; i < n; i++)
            cin >> data[i];
        sort(data, data+n);
        for (int i = 0; i < n; i++)
            cout << data[i] << " ";
        cout << endl;
        delete [] data;
        cin >> n;
    }
    return 0;
}