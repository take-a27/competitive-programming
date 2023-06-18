#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N+1]; for (int i=2; i<=N; i++) cin >> A[i];
    int B[N+1]; for (int i=3; i<=N; i++) cin >> B[i];
    int dp[N+1];
    dp[1] = 0;
    dp[2] = dp[1] + A[2];
    
    // dynamic programming
    for (int i=3; i<=N; i++) {
        dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
    }

    // restoration
    vector<int> ans;
    int place = N;
    while(true) {
        ans.push_back(place);
        if (place == 1) {
            break;
        }
        if (place != 2 && dp[place] == dp[place-2] + B[place]) {
            place = place - 2;
        } else {
            place = place - 1;
        }   
    }
    cout << ans.size() << endl;
    
    reverse(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        if (i >= 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
