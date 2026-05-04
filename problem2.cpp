#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long K;
    cin >> K;

    
    for (int i = 1; i < n; i++) {
        if ((A[i] - A[0]) % K != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

   
    vector<long long> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = A[i] / K;
    }


    sort(B.begin(), B.end());

  
    long long median = B[n / 2];


    long long operations = 0;
    for (int i = 0; i < n; i++) {
        operations += abs(B[i] - median);
    }

    cout << operations << endl;

    return 0;
}
