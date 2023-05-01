#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    int N; cin >> N;
    vector<int> diffNumOfStaff(T);
    fill(diffNumOfStaff.begin(), diffNumOfStaff.end(), 0);
    int L, R;
    for (int i=0; i<N; i++) {
        cin >> L >> R;
        diffNumOfStaff[L] += 1;
        diffNumOfStaff[R] -= 1;
    }
    vector<int> prefixStaffSum(T);
    for (int i=0; i<T; i++) {
        if (i==0) {
            prefixStaffSum[0] = diffNumOfStaff[0];
        } else {
            prefixStaffSum[i] = prefixStaffSum[i-1] + diffNumOfStaff[i];
        }
        cout << prefixStaffSum[i] << endl;
    }
}
