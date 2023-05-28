// /home/runner/Code/C_CPP/CppProjects/1.\ School/queue_by_myself/main.cpp

#define QUEUE_SIZE 5

#include <iostream>
using namespace std;


void insertQueue(int);
void deleteQueue();
void printQueue();

struct Queue {
    int q[QUEUE_SIZE];
    int back;
    int front;
    Queue () { back = -1, front = -1;}
};
Queue qu;

int main () {
    int a, n;
    while (1) {
        cout << "Choose a work to do:" << endl;
        cout << "1.insert" << endl;
        cout << "2.delete" << endl;
        cout << "3.print" << endl;
        cout << "4.exit" << endl;
        cin >> a;
        switch (a) {
            case 1:
                cin >> n;
                insertQueue(n);
                break;
            case 2:
                deleteQueue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                return 0;
        }
    }
}

void insertQueue (int n) {
    if (qu.back - qu.front== QUEUE_SIZE) {
        cout << "Queue is full." << endl;
    }else{
        qu.q[(++qu.back)%QUEUE_SIZE] = n;
    }
}
void deleteQueue () {
    if (qu.front == qu.back) {
        cout << "Queue is empty." << endl;
    }else{
        cout << "Deleted:" << qu.q[(++qu.front)%QUEUE_SIZE] << endl;
    }
}

void printQueue () {
    cout << "Elements in Queue:";
    for (int i = qu.front+1; i <= qu.back; i++) {
        cout << qu.q[i%QUEUE_SIZE] << " ";
    }
    cout << endl;
}