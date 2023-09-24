#include <iostream>
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
            stack<int> A_way, Stat, B_way;
            bool ac = 1;
            for (int i = N; i > 0; i++) {
                A_way.push(i);
            }
            while ( (!A_way.empty()) && (ac)) {
                temp = a.pop();
                if (temp > A_way.top()) {
                    while (temp > A_way.top)
                }
            }
            ///////
            cin >> M;
        }
        cin >> N;
    }
    
}
