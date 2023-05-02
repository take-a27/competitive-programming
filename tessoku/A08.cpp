#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector< vector<int> > X(H+1, vector<int>(W+1, 0));

    // 二次元の累積和を使って計算する場合、(1,1)の外側、つまり(0,0)に当たる部分も計算に使用する可能性があるので、
    // 配列も(1,1)から始めて、(0,0)は０埋めすることでうまく動作するようになる。
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) cin >> X[i][j];
    }

    vector< vector<int> > prefixSum(H+1, vector<int>(W+1, 0));
    prefixSum[1][1] = X[1][1];
    for (int i=1; i<=H; i++) {
        for (int j=2; j<=W; j++) prefixSum[i][j] = prefixSum[i][j-1] + X[i][j];
    }
    for (int i=2; i<=H; i++) {
        for (int j=1; j<=W; j++) prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j];
    }
    
    int Q; cin >> Q;
    int a[Q+1], b[Q+1], c[Q+1], d[Q+1];
    for (int i=1; i<=Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i=1; i<=Q; i++) cout << prefixSum[c[i]][d[i]] + prefixSum[a[i]-1][b[i]-1] - prefixSum[a[i]-1][d[i]] - prefixSum[c[i]][b[i]-1] << endl;
}
