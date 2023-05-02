#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int> A, int X);

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N); for (int i=0; i<N; i++) cin >> A[i];
    int answer = bSearch(A, X);
    cout << answer << endl;
}

int bSearch(vector<int> A, int X) {
    int L = 0;
    int R = A.size();
    int middle;
    while (L <= R) {
        middle = (L+R)/2;
        if (A[middle] == X) {
            return middle+1;
        } else if (A[middle] < X) {
            L = middle + 1;
        } else {
            R = middle;
        }
    }
    return -1;
}
