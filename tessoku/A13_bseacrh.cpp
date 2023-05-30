#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    long long A[N+1];
    long long sum = 0;
    for (int i=1; i<N+1; i++) cin >> A[i];
    for (int i=1; i<=N; i++) {
        int ok = 0;
        int ng = N+1;
        while (true) {
            int M = (ok+ng)/2;
            if (A[M] - A[i] <= K) {
                ok = M;
            } else if (A[M] - A[i] > K) {
                ng = M;
            }
            if (abs(ok - ng) == 1) {
                if (ok == 0) {
                    break;
                }
                sum += ok - i;
                break;
            }
        }
    }
    cout << sum << endl;
}
