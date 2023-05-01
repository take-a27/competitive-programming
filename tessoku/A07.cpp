#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D; cin >> D;
    int N; cin >> N;
    int L, R;
    vector<int> numGuest(D);
    fill(numGuest.begin(), numGuest.end(), 0);
    for (int i=0; i<N; i++) {
        cin >> L >> R;
        for (int i=L-1; i<=R-1; i++){
            numGuest[i]++;
        }
    }
    for (int i=0; i<D; i++) cout << numGuest[i] << endl;
    return 0;
}
