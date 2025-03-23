// ZeroJudge/e155

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> qu;
    while (n > 0) {
        for (int i = 1; i <= n; i++) {
            qu.push(i);
        }
            cout << "Discarded cards: ";
        while (n > 1) {
            cout << qu.front();
            qu.pop();
            n--;
            if (n > 1) {
                cout << ", ";
            }
            int temp = qu.front();
            qu.pop();
            qu.push(temp);
        }
        cout << endl;
        cout << "Remaining card: "
                        << qu.front() << endl;
        qu.pop();
        cin >> n;
    }
    return 0;
}
