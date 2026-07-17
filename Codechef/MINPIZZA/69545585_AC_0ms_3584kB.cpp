#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int totalSlices = n * x;
        int pizzas = (totalSlices + 3) / 4;

        cout << pizzas << endl;
    }

    return 0;
}