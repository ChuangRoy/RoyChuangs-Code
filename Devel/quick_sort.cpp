#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*quicksort*/

void quicksort (int a[], int start, int end) {
    if (start < end) {
        int i = start + 1;
        int j = end;
        int temp;
        while (1) {
            while (a[i] < a[start]&& i < end) { // cmp -> 1
                i++;
            }
            while (a[j] >= a[start] && j > start) { // cmp -> 0
                j--;
            }
            
            if (i >= j) {
                break;
            }else {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[start];
        a[start] = temp;
        quicksort(a, start, j - 1);
        quicksort(a, j + 1, end);
    }
}

int main(int argc, char** argv) {
    int n = 10;
    int a[n] = {3, 9, 3, 5, 6, 2, 4, 10, 7, 1};
    quicksort (a, 0, n-1); // quicksort(list, start, end)
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
	return 0;
}
