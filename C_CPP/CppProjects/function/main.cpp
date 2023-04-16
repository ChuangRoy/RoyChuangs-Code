#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


long long int sum (int x, int y) {
    return x+y;
}

long long int subtract (int x, int y) {
    return x-y;
}

long long int multiply (int x, int y) {
    return x*y;
}

long double divide (int x, int y) {
    return (long double) x/y;
}

void check_NPSC()
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
}

void counting () {
    int m, n, an;
    unsigned long long int sum = 0;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            an = i * pow(10, int(log10(j)+1));
            sum += an;
            sum += j;
        }
        
    cout << sum << endl;
}

void race () {
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
}

int main () {
    int mode;
    cout << "1. 加法" << endl;
    cout << "2. 減法" << endl;
    cout << "3. 乘法" << endl;
    cout << "4. 除法" << endl;
    cout << "5. 確認NPSC" << endl;
    cout << "6. 數數字" << endl;
    cout << "7. 比賽轉播" << endl;
    cin >> mode;
    long long int a, b;
    switch (mode) {
        case 1:cin >> a >> b;cout << a << "+" << b << "=" << sum(a, b) << endl;break;
        case 2:cin >> a >> b;cout << a << "-" << b << "=" << subtract(a, b) << endl;break;
        case 3:cin >> a >> b;cout << a << "*" << b << "=" << multiply(a, b) << endl;break;
        case 4:cin >> a >> b;cout << a << "/" << b << "=" << divide(a, b) << endl;break;
        case 5:check_NPSC();break;
        case 6:counting();break;
        case 7:race();break;
    }
    return 0;
}