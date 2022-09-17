#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



  /*
void random_list () {
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
        // cout << l[i] << endl;
    }
}
 */

int main () {
    int list_length = 5;
    int l[list_length] = {60, 50, 44, 82, 55};
    // random_list();
    for(int last_index = 0; last_index < list_length - 1; last_index++) { //sort
        for (int target_index = last_index + 1; target_index >= 0; target_index--) { // comparing from last index to 0
            if (l[target_index] < l[target_index-1]) {
                int temp = l[target_index-1];
                l[target_index-1] = l[target_index];
                l[target_index] = temp;
            }
        }
   }


    // print list
    for (int i = 0; i < list_length; i++)
        cout << l[i] << " ";
    cout << endl;
}
