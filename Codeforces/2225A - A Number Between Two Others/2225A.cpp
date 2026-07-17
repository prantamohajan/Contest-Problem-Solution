#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long x, y;
        cin >> x >> y;
 
        if (y >= 3 * x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}