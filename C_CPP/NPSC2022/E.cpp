#include <iostream>
using namespace std;

int main () {
    int n, m;
    cin >> n;
    cin >> m;
    int a[m] = {0};
    int b;
    int c;
    int maxI = 0;
    for (int i = 0; i < n; i++) {
        cin >> b;
        cin >> c;
        a[b-1] += c;
        if (a[b-1] > a[maxI])
            maxI = b-1;
    }
    cout << maxI+1 << endl;
    return 0;
}