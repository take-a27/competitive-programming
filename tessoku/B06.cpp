#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int Q;
    cin >> Q;
    int L[Q], R[Q];
    for (int i=0; i<Q; i++) cin >> L[i] >> R[i];

    // calc prefix sum
    int prefixSum[N];
    prefixSum[0] = A[0];
    for (int i=1; i<N; i++) prefixSum[i] = prefixSum[i-1] + A[i];

    int hitSum, missSum;
    for (int i=0; i<Q; i++)  {
        hitSum = prefixSum[R[i]-1] - prefixSum[L[i]-2];
        missSum = R[i] - (L[i] - 1) - hitSum;
        if (hitSum > missSum) {
            cout << "win" << endl;
        } else if (hitSum == missSum) {
            cout << "draw" << endl;
        } else {
            cout << "lose" << endl;
        }
    }
}