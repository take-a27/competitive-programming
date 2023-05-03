#include <iostream>
#include <vector>
using namespace std;

// using binary search
int main() {
    long long N, K; cin >> N >> K;
    vector<int> A(N); for (int i=0; i<N; i++) cin >> A[i];

    long long L = 1;
    long long R = 1000000000;
    while (L < R) {
        long long M = (L+R)/2;
        long long sum = 0;
        for (long long i=0; i < N; i++) sum += M / A[i];
        // the anwser is the earliest time, so even if sum matches K, keep searching earlier time
        if (sum >= K) {
            R = M;
        } else if (sum < K) {
            L = M+1;
        }
    }
    // if sum didn't match K, then L matches R and that's the answer
    cout << L << endl;
}
