#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S; cin >> S;
    string T; cin >> T;
    int dp[S.size()+1][T.size()+1];
    dp[0][0] = 0;

    for (int i=0; i<=S.size(); i++) {
        for (int j=0; j<=T.size(); j++) {
            if (i==0) {
                dp[0][j] = j;
                continue;
            }
            if (j==0) {
                dp[i][0] = i;
                continue;
            }
            if (S[i-1] == T[j-1]) {
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]));
            } else {
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
            }
        }
    }

    cout << dp[S.size()][T.size()] << endl;
}
