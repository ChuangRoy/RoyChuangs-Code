#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main () {
    clock_t start_time, end_time; // 儲存時間用的變數
    int list_length = 100;
    int l[500000];
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
    }
    start_time = clock(); // 計算開始時間
    for(int last_index = 0; last_index < list_length - 1; last_index++) { //sort
        for (int target_index = last_index + 1; target_index >= 0; target_index--) { // comparing from last index to 0
            if (l[target_index] < l[target_index-1]) {
                int temp = l[target_index-1];
                l[target_index-1] = l[target_index];
                l[target_index] = temp;
            }
        }
   }


    
    end_time = clock(); // 計算結束時間
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // 計算實際花費時間

    cout << "100 numbers calculation time:" << cpu_time_used <<endl;
/////////////////////////////////////////////////////////////////////////////

    list_length = 10000;
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
    }
    start_time = clock(); // 計算開始時間
    for(int last_index = 0; last_index < list_length - 1; last_index++) { //sort
        for (int target_index = last_index + 1; target_index >= 0; target_index--) { // comparing from last index to 0
            if (l[target_index] < l[target_index-1]) {
                int temp = l[target_index-1];
                l[target_index-1] = l[target_index];
                l[target_index] = temp;
            }
        }
   }


    
    end_time = clock(); // 計算結束時間
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // 計算實際花費時間

    cout << "10000 numbers calculation time:" << cpu_time_used <<endl;
/////////////////////////////////////////////////////////////////////////////


    list_length = 100000;
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
    }
    start_time = clock(); // 計算開始時間
    for(int last_index = 0; last_index < list_length - 1; last_index++) { //sort
        for (int target_index = last_index + 1; target_index >= 0; target_index--) { // comparing from last index to 0
            if (l[target_index] < l[target_index-1]) {
                int temp = l[target_index-1];
                l[target_index-1] = l[target_index];
                l[target_index] = temp;
            }
        }
   }


    
    end_time = clock(); // 計算結束時間
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // 計算實際花費時間

    cout << "100000 numbers calculation time:" << cpu_time_used <<endl;

/////////////////////////////////////////////////////////////////////////////


    list_length = 500000;
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
    }
    start_time = clock(); // 計算開始時間
    for(int last_index = 0; last_index < list_length - 1; last_index++) { //sort
        for (int target_index = last_index + 1; target_index >= 0; target_index--) { // comparing from last index to 0
            if (l[target_index] < l[target_index-1]) {
                int temp = l[target_index-1];
                l[target_index-1] = l[target_index];
                l[target_index] = temp;
            }
        }
   }


    
    end_time = clock(); // 計算結束時間
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // 計算實際花費時間

    cout << "500000 numbers calculation time:" << cpu_time_used <<endl;
}
