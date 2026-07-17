#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n == 0) {
            cout << 0 << '\n';
            continue;
        }
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());
        int diff = mx - mn;
        cout << (diff + 1) / 2 << '\n';
    }
    return 0;
}