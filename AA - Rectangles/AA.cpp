#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        count += (n / i - i + 1);
    }

    cout << count << endl;
    return 0;
}