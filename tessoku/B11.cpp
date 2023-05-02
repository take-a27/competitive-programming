#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N); for (int i=0; i<N; i++) cin >> A[i];
    int Q; cin >>Q;
    vector<int> X(Q); for (int i=0; i<Q; i++) cin >> X[i];
    sort(A.begin(), A.end());
    for (int i=0; i<Q; i++) {
        int ans = lower_bound(A.begin(), A.end(), X[i]) - A.begin();
        cout << ans << endl;
    }
}
