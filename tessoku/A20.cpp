#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S; cin >> S;
    string T; cin >> T;
    int dp[S.size()+1][T.size()+1];

    // initialize
    for (int i=0; i<=S.size(); i++) {
        dp[i][0] = 0;
    }
    for (int i=0; i<=T.size(); i++) {
        dp[0][i] = 0;
    }

    // dp
    for (int i=1; i<=S.size(); i++) {
        for (int j=1; j<=T.size(); j++) {
            if (S[i-1] == T[j-1]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[S.size()][T.size()] << endl;
}