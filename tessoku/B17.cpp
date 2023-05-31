#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int N; cin >> N;
    int h[N+1]; for (int i=1; i<=N; i++) cin >> h[i];
    int dp[N+1];
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i=3; i<=N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    int place = N;
    vector<int> ans;
    while(true) {
        ans.push_back(place);
        if (place == 1) break;
        if (place != 2 || dp[place] == dp[place-2] + abs(h[place] - h[place-2])) {
            place = place - 2;
        } else {
            place = place - 1;
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
