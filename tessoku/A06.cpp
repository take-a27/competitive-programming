#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int L[Q], R[Q];
    for (int i=0; i<Q; i++) cin >> L[i] >> R[i];

    int prefixSum[N];
    prefixSum[0] = A[0];
    for (int i=1; i<N; i++) prefixSum[i] = prefixSum[i-1] + A[i];
    for (int i=0; i<Q; i++) cout << prefixSum[R[i]-1] - prefixSum[L[i]-2] << endl;
}
