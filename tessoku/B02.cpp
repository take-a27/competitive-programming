#include <iostream>
#include <vector>
using namespace std;

vector<int> getDivisor(int n) {
    vector<int> divisor;
    for (int i=1; i <= n; i++) { // 割り算の時は i=1 から始める
        if (n % i == 0) {
            divisor.push_back(i);
        }
    }
    return divisor;
}

int main() {
    int A, B;
    cin >> A >> B;
    vector<int> divisor;
    divisor  = getDivisor(100);
    for (int i = A; i <= B; i++) {
        for (int j = 0; j < divisor.size(); j++) {
            if (i == divisor[j]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
