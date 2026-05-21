#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        int remaining = Z - Y;
        int maxMangoes = remaining / X;

        cout << maxMangoes << "\n";
    }

    return 0;
}