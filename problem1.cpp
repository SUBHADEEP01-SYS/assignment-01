#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    string t = s + s;

    vector<int> freq(26, 0);
    int left = 0, max_sum = 0, curr_sum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = t[right] - 'a';

        while (freq[idx] > 0) {
            int left_idx = t[left] - 'a';
            freq[left_idx]--;
            curr_sum -= (left_idx + 1);
            left++;
        }

        
        freq[idx]++;
        curr_sum += (idx + 1);

        
        while (right - left + 1 > n) {
            int left_idx = t[left] - 'a';
            freq[left_idx]--;
            curr_sum -= (left_idx + 1);
            left++;
        }

        max_sum = max(max_sum, curr_sum);
    }

    cout << max_sum << endl;
    return 0;
}
