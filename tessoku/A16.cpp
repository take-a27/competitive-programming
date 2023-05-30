#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N+1]; for (int i=2; i<=N; i++) cin >> A[i];
    int B[N+1]; for (int i=3; i<=N; i++) cin >> B[i];
    vector<int> dp(N+1, 0);
    dp[1] = 0;
    dp[2] = A[2];
    for (int i=3; i<=N; i++) {
        dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
    }
    cout << dp[N] << endl;
}
