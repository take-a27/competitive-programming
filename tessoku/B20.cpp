#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S;
    cin >> T;
    int s = S.size();
    int t = T.size();

    int dp[s+1][t+1];
    for (int i=0; i<=s; i++) dp[i][0] = i;
    for (int i=0; i<=t; i++) dp[0][i] = i;
    
    for (int i=1; i<=s; i++) {
        for (int j=1; j<=t; j++) {
            if (S[i-1] == T[j-1]) {
                dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]));
            } else {
                dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
            }  
        }
    }

    cout << dp[s][t] << endl;
}
