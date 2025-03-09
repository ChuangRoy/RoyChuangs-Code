#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string line;
    while(getline(cin, line)) {
        // convert
        for (int i = 0; i < int(line.size()); ++i)
            if (line[i] == ',')
                line[i] = ' ';
        stringstream ss(line);
        vector<int> even;
        vector<int> numbers;
        int number;
        while (ss >> number) {
            numbers.push_back(number);
            if (number % 2 == 0) {
                even.push_back(number);
            }
        }
        sort(even.begin(), even.end());
        int i = -1;
        for (int j = 0; j < numbers.size(); j++) {
            if (j > 0) cout << ',';
            if (numbers[j] % 2) cout << numbers[j];
            else cout << even[++i];
        }
        cout << '\n';
    }
    return 0;
}