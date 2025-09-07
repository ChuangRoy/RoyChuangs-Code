#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int k;
	while (n--) {
		cin >> k;
		if (k >= 80)
			cout << "AaW不可能是電神一定是成績改錯了" << endl;
		else if (80 > k && k >= 60)
			cout << "好扯竟然有及格" << endl;
		else if (60 > k && k >= 40)
			cout << "快去準備補考" << endl;
		else
			cout << "沒救了QAQ" << endl;
	}
}