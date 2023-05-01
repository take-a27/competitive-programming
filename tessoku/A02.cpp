#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int a[N];

    for (int i=0; i<N; i++) { cin >> a[i]; } // 空白区切りの複数の入力を受け取る
    for (int i=0; i<N; i++) { 
        if (a[i] == X ) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
