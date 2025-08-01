#include <bits/stdc++.h>
// #define int unsigned long long
using namespace std;

const int inf = 1e9;
const unsigned long long arr_size = (1 << 20) + 1;
int elevators_needed[arr_size];
int weights_record[arr_size];
long long weights[20];

int main () {
	int n, weight_limit;
	cin >> n >> weight_limit;
	elevators_needed[0] = 1;
	weights_record[0] = 0;
	for (int i = 0; i < n; i++) cin >> weights[i];
	// i going through permutaions via bitmask
	for (unsigned long long i = 1; i < (1 << n); i++) {
		elevators_needed[i] = inf;
		weights_record[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				unsigned long long prev = i ^ (1 << j);
				if (weights_record[prev] + weights[j] <= weight_limit && (elevators_needed[prev] < elevators_needed[i]  || (elevators_needed[prev] == elevators_needed[i] && weights_record[prev] + weights[j] < weights_record[i]))) {
					elevators_needed[i] = elevators_needed[prev];
					weights_record[i] = weights_record[prev] + weights[j];
				}
				if (weights_record[prev] + weights[j] > weight_limit && (elevators_needed[prev] + 1 < elevators_needed[i] || (elevators_needed[prev] + 1 == elevators_needed[i] && weights[j] < weights_record[i]))) {
					elevators_needed[i] = elevators_needed[prev] + 1;
					weights_record[i] = weights[j];
				}
			}
		}
	}
	cout << elevators_needed[(1 << n) - 1] << endl;
	return 0;
}
