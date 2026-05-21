#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        if (X > Y) cout << "A\n";
        else cout << "B\n";
    }

    return 0;
}