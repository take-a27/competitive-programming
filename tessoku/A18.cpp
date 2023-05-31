#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, S; cin >> N >> S;
    int A[N+1]; for (int i=1; i<=N; i++) cin >> A[i];
    int dp[N+1][S+1];
    dp[0][0] = true;
    for (int i=1; i<=N; i++) dp[0][i] = false;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=S; j++) {
            if (dp[i-1][j] == true) {
                dp[i][j] = true;
                continue;
            }
            if (A[i] > j) {
                dp[i][j] = false;
            } else {
                if (dp[i-1][j-A[i]] == true) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }
    if (dp[N][S] == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
