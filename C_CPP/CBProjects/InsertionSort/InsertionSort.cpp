#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int list_length = 5;
int l[5] = {60, 50, 44, 82, 55};

void random_list () {
    srand (time(NULL));
    for (int i = 0; i < list_length; i++) {
        l[i] = rand();
        // cout << l[i] << endl;
    }
}

void insert_into_list (int position, int target) { // Insert target in front of position
    int backup[list_length];
    for (int i = 0; i < list_length; i++) //copy list
        backup[i] = l[i];
    for (int i = position; i < target; i++) // every index + 1
        l[i+1] = backup[i];
    l[position] = backup[target];
    // debug
    for (int i = 0; i < list_length; i++)
        cout << "[DEBUG]: l[" << i << "] = " << l[i] << endl;
}

int main () {
    // random_list();
    int last_index = 0;
    bool sort_finish = 0;
    while (!sort_finish) { //sort
        int target_index = last_index + 1;
        for (int i = 0; i <= last_index; i++) {
            for (int i = target_index; i < 0; i--)
                if (l[i] <ｌ[i-1])
                    int temp = l[i];l[i] = l[]
        }

    }


}
