// C_CPP/CppProjects/1.\ School/queue_stl/main.cpp

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> mqueue;
    bool run = 1;
    int a, n;
    while (run) {
        cout << "Choose a work to do:" << endl;
        cout << "1.insert" << endl;
        cout << "2.delete" << endl;
        cout << "3.clear" << endl;
        cout << "4.exit" << endl;
        cin >> a;
        switch (a) {
            case 1:
                cin >> n;
                mqueue.push(n);
                break;
            case 2:
                cout << "Deleted: " << mqueue.front() << endl;
                mqueue.pop();
                break;
            case 3:
                cout << "Deleted: ";
                while (!mqueue.empty()) {
                    cout << mqueue.front() << " ";
                    mqueue.pop();
                }
                cout << endl;
                break;
            case 4:
                run = 0;
                break;
            default:
                cout << "Error" << endl;
                return 1;
    }
  }
  cout << endl;
}