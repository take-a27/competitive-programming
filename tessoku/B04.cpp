#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;
    int answer = 0;

    int numOfDigit = N.size();
    for (int i=0; i<numOfDigit; i++) {
        answer += (N[i]-'0') * (1 << (numOfDigit - i - 1));
    }

    cout << answer << endl;
}
