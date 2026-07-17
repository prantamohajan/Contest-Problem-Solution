#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;
    if (n <= 1) {
        cout << "No" << endl;
        return 0;
    }
    if (n <= 3) {
        cout << "Yes" << endl;
        return 0;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        cout << "No" << endl;
        return 0;
    }
    bool isPrime = true;
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
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
}