#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];

    int sum;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) {
                continue;
            }
            for (int k=0; k<N; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (A[i]+A[j]+A[k] == 1000) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
