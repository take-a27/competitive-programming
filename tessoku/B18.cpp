#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, S; cin >> N >> S;
    int A[N+1]; for (int i=1; i<=N; i++) cin >> A[i];
    int dp[N+1][S+1];
    dp[0][0] = true;
    for (int i=1; i<=S; i++) dp[0][i] = false;

    // dp
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=S; j++) {
            if (j >= A[i]) {
                if (dp[i-1][j] == true) dp[i][j] = true;
                else if (dp[i-1][j-A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            } else {
                if (dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if (dp[N][S] == false) {
        cout << -1 << endl;
        return 0;
    }
    
    // restoration
    vector<int> ans;
    int sum = S;
    for (int i=N;; i--) {
        if (sum == 0) { 
            break;
        }
        if (dp[i-1][sum] == true) continue;
        else { 
            ans.push_back(i);
            sum = sum - A[i];
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        if (i >= 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
