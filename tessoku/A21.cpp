#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int P[N+1], A[N+1];
    for (int i=1; i<=N; i++) cin >> P[i] >> A[i];

    int dp[N+1][N+1];
    dp[1][N] = 0;
    int removeL, removeR;

    for (int len=N-2; len >= 0; len--) {
        for (int L=1; L<=N - len; L++) {
            int R = len + L;
            // when lift block is removing
            if (L <= P[L-1] && P[L-1] <= R) {
                removeL = dp[L-1][R] + A[L-1];
            } else {
                removeL = dp[L-1][R];
            }
            // when right block is removing
            if (L <= P[R+1] && P[R+1] <= R) {
                removeR = dp[L][R+1] + A[R+1];
            } else {
                removeR = dp[L][R+1];
            }

            if (L == 1) {
                dp[L][R] = removeR;
            } else if (R == N) {
                dp[L][R] = removeL;
            } else if (removeR >= removeL) {
                dp[L][R] = removeR;
            } else {
                dp[L][R] = removeL;
            }
        }
    }

    int answer = 0;
    for (int i=1; i<=N; i++) {
        answer = max(answer, dp[i][i]);
    }
    cout << answer << endl;
}