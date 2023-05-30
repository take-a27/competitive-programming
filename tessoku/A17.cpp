#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N+1], B[N+1], dp[N+1];
    for (int i=2; i<=N; i++) cin >> A[i];
    for (int i=3; i<=N; i++) cin >> B[i];

    // dp
    dp[1] = 0;
    dp[2] = A[2];
    for (int i=3; i<=N; i++) {
        dp[i] = min(dp[i-1]+A[i], dp[i-2]+B[i]);
    }

    // find the way
    int current = N;
    vector<int> ans;
    while (true) {
        ans.push_back(current);
        if (current == 1) {
            break;
        }
        if (dp[current] == dp[current-1]+A[current] || current == 2) {
            current = current - 1;
        } else {
            current = current - 2;
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
