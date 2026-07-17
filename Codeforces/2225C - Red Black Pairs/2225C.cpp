#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
void solve() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
 
    for (int i = 0; i < n; ++i) {
        if (dp[i] == INF) continue;
 
        int cost_vertical_R = (s[0][i] != 'R') + (s[1][i] != 'R');
        int cost_vertical_B = (s[0][i] != 'B') + (s[1][i] != 'B');
        dp[i + 1] = min(dp[i + 1], dp[i] + min(cost_vertical_R, cost_vertical_B));
 
        if (i + 1 < n) {
            int cost_top_R = (s[0][i] != 'R') + (s[0][i + 1] != 'R');
            int cost_top_B = (s[0][i] != 'B') + (s[0][i + 1] != 'B');
            
            int cost_bottom_R = (s[1][i] != 'R') + (s[1][i + 1] != 'R');
            int cost_bottom_B = (s[1][i] != 'B') + (s[1][i + 1] != 'B');
 
            int total_horiz_cost = min(cost_top_R, cost_top_B) + min(cost_bottom_R, cost_bottom_B);
            dp[i + 2] = min(dp[i + 2], dp[i] + total_horiz_cost);
        }
    }
 
    cout << dp[n] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}