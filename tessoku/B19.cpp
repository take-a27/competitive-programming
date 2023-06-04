#include <iostream>
using namespace std;

int main() {
    long long N, W; cin >> N >> W;
    long long w[N+1], v[N+1];
    for (int i=1; i<=N; i++) {
        cin >> w[i] >> v[i];
    }
    
    int maxV = 100000;
    long long dp[N+1][maxV+1];
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=maxV; j++) {
            dp[i][j] = W * 10LL;
        }
    }

    dp[0][0] = 0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=maxV; j++) {
            if (v[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);            
            }
        }
    }

    for (int i=maxV; i >= 0; i--) {
        if (dp[N][i] <= W) {
            cout << i << endl;
            break;
        }
    }
}
