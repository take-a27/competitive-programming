#include <iostream>
using namespace std;;

int main() {
    int N, W; cin >> N >> W;
    int w[N+1], v[N+1]; for (int i=1; i<=N; i++) cin >> w[i] >> v[i];
    long long dp[N+1][W+1];
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=W; j++) {
            dp[i][j] = 0;
        }
    }

    // i 番目のアイテムまでの中の、重さ j の時の価値 dp[i][j]
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=W; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    long long maxVal = 0;
    for (int i=1; i<=W; i++) {
        if (maxVal < dp[N][i]) maxVal = dp[N][i];
    }

    cout << maxVal << endl;
}
