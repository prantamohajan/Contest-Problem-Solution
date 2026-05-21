#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, N;
        cin >> X >> N;

        int Test = X / 10;
        int score = Test * N;

        cout << score << "\n";
    }

    return 0;
}