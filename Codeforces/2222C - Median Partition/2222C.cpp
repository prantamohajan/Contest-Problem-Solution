#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    vector<int> sorted_a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    sort(sorted_a.begin(), sorted_a.end());
    int X = sorted_a[n / 2];
 
    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
 
    for (int i = 1; i <= n; i++) {
        int lt = 0, gt = 0, eq = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < X) lt++;
            else if (a[j] > X) gt++;
            else eq++;
 
            int L = i - j;
            if (L % 2 == 1) {
                if (eq > 0 && 2 * lt < L && 2 * gt < L) {
                    if (dp[j] >= 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
    }
    cout << dp[n] << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}