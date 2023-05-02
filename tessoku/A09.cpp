#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, H, W; cin >> H >> W >> N;
    int A[N+1], B[N+1], C[N+1], D[N+1];
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // fill the increments of snow
    vector< vector<int> > incr(H+1, vector<int>(W+1, 0)); 
    for (int i=1; i<=N; i++) {
        incr[A[i]][B[i]] += 1;
        incr[C[i]+1][D[i]+1] += 1;
        incr[A[i]][D[i]+1] -= 1;
        incr[C[i]+1][B[i]] -= 1;
    }

    // calculate prefix sum -> actual amount of snow will be filled in
    // calculate horizontally
    vector< vector<int> > pSum(H+1, vector<int>(W+1,0));
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) pSum[i][j] = incr[i][j] + pSum[i][j-1];
    }
    // calculate vertically
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) pSum[i][j] = pSum[i][j] + pSum[i-1][j];
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (j>=2) cout << " ";
            cout << pSum[i][j];
        }
        cout << endl;
    }
}
