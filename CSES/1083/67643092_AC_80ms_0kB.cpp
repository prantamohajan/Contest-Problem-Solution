#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int X;
        cin >> X;
        sum += X;
    }
    long long total = (long long)n * (n + 1) / 2;
    cout << (total - sum) << endl;
    return 0;
}

