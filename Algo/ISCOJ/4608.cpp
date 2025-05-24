#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N; cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    if (N & 1) {
        cout << nums[N >> 1] << ".00" << ' ';
    } else {
        long long a = nums[N >> 1], b = nums[(N >> 1) - 1];
        cout << fixed << setprecision(2) << (long double) (a + b) / 2 << ' ';
    }
    long long sum = 0;
    map<int, int> freq;
    int mode = 0x3f3f3f3f;
    int mode_freq = 0;
    for (auto i : nums) {
        freq[i]++;
        if (freq[i] > mode_freq) {
            mode = i;
            mode_freq = freq[i];
        } else if (freq[i] == mode_freq && i < mode) {
            mode = i;
        }
        sum += i;
    }
    cout << mode << ' ';
    cout << fixed << setprecision(2) << (long double) sum / N << '\n';
    return 0;
}