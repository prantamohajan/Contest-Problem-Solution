#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        int calls = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] == a[r]) {
                break;
            }
            calls++;
            l++;
            r--;
        }
        cout << calls << '\n';
    }
    return 0;
}