#include <iostream>
using namespace std;

int main() {
    int maxV = 1000;
    long long N, W; cin >> N >> W;
    int w[N+1], v[N+1]; for (int i=1; i<=N; i++) cin >> w[i] >> v[i];
    long long dp[N+1][maxV * N + 1];
    dp[0][0] = 0;
    for (int i=1; i<=maxV * N; i++) {
        dp[0][i] = W * 100LL;
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j <= maxV * N; j++) {
            if (j >= v[i]) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = 0;
    for (int i=0; i <= maxV * N; i++) {
        if (dp[N][i] <= W) ans = i;
    }

    cout << ans << endl;
}
