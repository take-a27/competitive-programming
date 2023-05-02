#include <iostream>
#include <vector>
using namespace std;


int main() {
    int H = 1501;
    int W = 1501;
    int N; cin >> N;
    vector< vector<int> > Z(H+1, vector<int>(W+1, 0));
    int x,y;
    for (int i=1; i<=N; i++) {
        cin >> x >> y;
        Z[x][y] += 1;
    }

    // calc prefix sum
    vector< vector<int> > pSum(H+1, vector<int>(W+1, 0));
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) pSum[i][j] = pSum[i][j-1] + Z[i][j];
    }
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) pSum[i][j] = pSum[i-1][j] + pSum[i][j];
    }

    int Q; cin >> Q;
    int a[Q+1], b[Q+1], c[Q+1], d[Q+1];
    for (int i=1; i<=Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i=1; i<=Q; i++) cout << pSum[a[i]-1][b[i]-1] + pSum[c[i]][d[i]] - pSum[a[i]-1][d[i]] - pSum[c[i]][b[i]-1] << endl;
}