#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int C, X, Y;
        cin >> C >> X >> Y;
        int cost = (C - X) * Y;
        cout << cost << endl;
    }

    return 0;
}