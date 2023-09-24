#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n][4];
    for (int i = 0; i < n; i++)  {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        cout << a[i][0] << " "<< a[i][1] << " " << a[i][2] << " " << a[i][3] << " ";
        if (a[i][2]-a[i][1]==a[i][1]-a[i][0])
            cout << a[i][3]+a[i][1]-a[i][0] << endl;
        else
            cout << a[i][3]*a[i][1]/a[i][0] << endl;
    }
    return 0;
}
