#include <iostream>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n <= 1) {
        cout << "No" << endl;
        return 0;
    }
    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
