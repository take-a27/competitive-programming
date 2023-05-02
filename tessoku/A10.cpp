#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N+1, 0); for (int i=1; i<=N; i++) cin >> A[i];
    int D; cin >> D;
    vector<int> L(D+1, 0), R(D+1, 0); for (int i=1; i<=D; i++) cin >> L[i] >> R[i];
    vector<int> maxL(N+1, 0), maxR(N+1, 0);

    maxL[1] = A[1]; 
    for (int i=2; i<=N; i++) maxL[i] = max(A[i], maxL[i-1]);
    maxR[N] = A[N];
    for (int i=N-1; i>=1; i--) maxR[i] = max(A[i], maxR[i+1]);

    for (int d=1; d<=D; d++) {
        cout << max(maxL[L[d]-1], maxR[R[d]+1]) << endl;
    }   
}
