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
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        vector<long long> ans(n);
        long long cur_min = LLONG_MAX;
        for (int i = 1; i <= n; ++i) {
            long long val = prefix[i] / i;
            cur_min = min(cur_min, val);
            ans[i - 1] = cur_min;
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}