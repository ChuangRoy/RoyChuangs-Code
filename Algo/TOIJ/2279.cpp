#pragma GCC optimize("O0")

#include <bits/stdc++.h>
#include <random>
#include <chrono>

#define SIZE (52099800)

using namespace std;

char *c, *k;

int main () {
    auto clk = clock();
    int n; cin >> n;
    k = new char[10585760];
    switch (n) {
    case 0:
        cout << 0 << endl;
        break;
    case 1:
        cout << 0 << endl;
        break;
    case 2:
        cout << 2 << endl;
        while (1) {n = 0;}
        break;
    case 3: 
    {
        cout << 3 << endl;
        c = new char[SIZE];
        break;
    }
    case 4:
    {
        cout << 4 << endl;
        int *arr = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            arr[i] = i;
        }
        delete[] arr;
        break;
    }
    case 5:
    {
        cout << 5 << endl;
        while (1) {cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";}
        break;
    }
    case 6:
    {
        cout << 6 << endl;
        return -114514;
    }
    case 7:
    {
        cout << 7 << endl;
        vector<long long> vec(1e15);
        break;
    }
    case 8:
        cout << 8 << endl;
        break;
    case 9:
        while (double (clock() - clk) / CLOCKS_PER_SEC < 0.996);
        cout << 9 << endl;
        break;
    }
    return 0;
}