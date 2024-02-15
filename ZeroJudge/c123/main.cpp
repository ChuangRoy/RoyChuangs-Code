#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main () {
    int M, N;
    cin >> N;
    while (N) {
        queue<int> a;
        cin >> M;
        while (M) {
            a.push(M);
            int temp;
            for (int i = 1; i < N; i++) {
                cin >> temp;
                a.push(temp);
            }
            ///////
            stack<int> A_way, Station;
            bool ok = 1;
            int target;
            for (int i = N; i > 0; i--) {
                A_way.push(i);
            }
            while (!a.empty() && ok) {
                target = a.front();
                a.pop();
                if (!A_way.empty() && A_way.top() <= target) {
                    while (A_way.top() < target) {
                        Station.push(A_way.top());
                        A_way.pop();
                    }
                    A_way.pop();
                }else if (!Station.empty() && Station.top() == target){
                    Station.pop();
                }else{
                    ok  = 0;
                    break;
                }
            }
            if (ok) {
                cout << "Yes"  << endl;
            }else{
                cout << "No" << endl;
            }
            ///////
            cin >> M;
        }
        cin >> N;
    }
    return 0;
}
