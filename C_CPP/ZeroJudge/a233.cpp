#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<long long> a(N, -1);
vector<long long> record(N, -1);

void sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    sort(l, mid);
    sort(mid+1, r);
    // merge a b
    int la = l, lb = mid + 1, i = l;
    while (la <= mid && lb <= r) {
        if (a[la] > a[lb]) {
            record[i] = a[lb];
            lb++;
            i++;
        }
        else {
            record[i] = a[la];
            la++;
            i++;
        }
    }
    bool flag = 0;
    if (la>mid) flag = 1;
    while (i <= r) {
        if (flag) {
            record[i] = a[lb];
            lb++;
            i++;
        }
        else {
            record[i] = a[la];
            la++;
            i++;
        }
    }
    for (int j = l; j <= r; j++) a[j] = record[j];
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(0, n-1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}