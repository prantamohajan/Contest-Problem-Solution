#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (b == 0) {
            cout << 1 << endl;
            continue;
        }

        int d = a % 10;

        vector<int> cycle;

        if (d == 0 || d == 1 || d == 5 || d == 6) {
            cout << d << endl;
            continue;
        }
        else if (d == 2) cycle = {2,4,8,6};
        else if (d == 3) cycle = {3,9,7,1};
        else if (d == 4) cycle = {4,6};
        else if (d == 7) cycle = {7,9,3,1};
        else if (d == 8) cycle = {8,4,2,6};
        else if (d == 9) cycle = {9,1};

        int len = cycle.size();
        int idx = b % len;
        if (idx == 0) idx = len;

        cout << cycle[idx - 1] << endl;
    }
}