#include <bits/stdc++.h>
using namespace std;

int main () {
    int h,m;
    cin >> h >> m;
    int minutes = h * 60 + m;
    if (minutes <= 60){
        cout << "Impossible" << endl;
    }
    else if (minutes <= 150){
        cout << "Stop Crying" << endl;
    }
    else if (minutes <= 240){
        cout << "You Gonna Die" << endl;
    }
    else {
        cout << "Good Morning" << endl;
    }
}