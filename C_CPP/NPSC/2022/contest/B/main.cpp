#include <iostream>
#include <cmath>
using namespace std;
bool return_0 = 0;


void merge (int a[], int k, int b[], int n, int c[], int m) {
    string input;
    int i = 0, j = 0;
    while (i < n&& j < m) {
        cout << 2  << " " << b[i] << " " << c[j] << endl;
        cin >> input;
        if (input=="Nie") {
            a[i+j] = c[j];
            j++;
        }
        else if(input=="Tak"){
            a[i+j] = b[i];
            i++;
        }else if(input=="Gotowe") {
            i = n; j = m;return_0=1;
        }
    }
    if (j < m) {
        for (int l=0; l < m-j; l++) {
            a[i+j+l] = c[j+l];
        }
    }else if(i < n) {
        for (int l=0; l < n-i; l++) {
            a[i+j+l] = b[i+l];
        }
    }
}

void sort (int a[], int k) {
    if (k > 1) {
        int l = ceil(k / 2.0);
        int b[l], c[k-l];
        for (int i = 0; i < l; i++) {
            b[i] = a[i];
        }
        for (int i = 0; i < k-l; i++) {
            c[i] = a[l+i];
        }
        sort(b, l);
        sort(c, k-l);
        merge(a, k, b, l, c, k-l);
    }
}


int main () {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = i+1;
    sort(a, N);
    if (!return_0) {
        cout << N << " ";
        for (int i = 0; i < N; i++)
            cout << a[i] << " ";
        cout << endl;
        cin >> N;
    }
    return 0;
}
