#include <iostream>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];

    int sum = 0;
    for (int i=0; i<(1<<N); i++) {
        for (int j=1; j<N; j++) {
            // Nを2^jで割った時の整数部分を２で割った時の余りが１だったら
            if ((N / (1<<j)) % 2 == 1) {
                sum += A[j];
                if (sum == S) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
