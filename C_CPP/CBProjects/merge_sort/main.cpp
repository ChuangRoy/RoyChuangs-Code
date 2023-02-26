#include <iostream>
#include <cmath>
using namespace std;

void merge (int a[], int k, int b[], int n, int c[], int m) {
    int i = 0, j = 0;
    while (i < n&& j < m) {
        if (b[i] > c[j]) {
            a[i+j] = c[j];
            j++;
        }
        else if(b[i] < c[j]){
            a[i+j] = b[i];
            i++;
        }else if(b[i] == c[j]) {
            a[i+j] = c[j];
            j++;
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
    int list_length = 7;
    int n[list_length] = {3, 6, 5, 4, 10, 100, 5};
    sort(n, list_length);
    for (int i = 0; i < list_length; i++) {
        cout << n[i] << " ";
    }
}