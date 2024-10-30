#include <iostream>

using namespace std;

int main()
{
    //78、80、83、67
    char a[10],b[10],c[10],d[10];
    cin >> a >> b >> c >> d;
    int a1,b1,c1,d1;
    a1 = a[0];
    b1 = b[0];
    c1 = c[0];
    d1 = d[0];
    if (a1 == 78 && b1 == 80 && c1 == 83 && d1 == 67)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
