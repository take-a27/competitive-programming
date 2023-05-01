#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int count = 0;
    for (int i=1; i <= N; i++) {
        if (i >= K) continue;
        for (int j=1; j <= N; j++) {
            if (i + j >= K) continue;
            int n = K - (i+j); 
            if (n <= N) count++;
        }
    }
    cout << count << endl;
}
