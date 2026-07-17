#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;
        
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        dp[0][0] = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= x; ++j) {
                if (dp[i][j] == -1) continue;
                int seated = dp[i][j];
                
                dp[i + 1][j] = max(dp[i + 1][j], seated);
                
                char p = u[i];
                long long rem_cap = 1LL * j * s - seated;
                int rem_empty = x - j;
                if ((p == 'I' || p == 'A') && rem_empty > 0) {
                    int nj = j + 1;
                    int ns = seated + 1;
                    if (nj <= x) {
                        dp[i + 1][nj] = max(dp[i + 1][nj], ns);
                    }
                }
                if ((p == 'E' || p == 'A') && rem_cap > 0) {
                    int nj = j;
                    int ns = seated + 1;
                    dp[i + 1][nj] = max(dp[i + 1][nj], ns);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= x; ++j) {
            if (dp[n][j] != -1) {
                ans = max(ans, dp[n][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}