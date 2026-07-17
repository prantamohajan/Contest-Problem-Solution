#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> subtask_value(n);
    int total_max_score = 100 * n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        subtask_value[i] = 100 / a[i];
    }
    bitset<1001> dp; 
    dp[0] = 1; 
 
    for (int i = 0; i < n; i++) {
        bitset<1001> next_dp;
        int val = subtask_value[i];
        int count = a[i];
        for (int j = 0; j <= count; j++) {
            next_dp |= (dp << (j * val));
        }
        dp = next_dp;
    }

    bool possible = true;
    for (int k = 0; k <= total_max_score; k++) {
        if (!dp[k]) {
            possible = false;
            break;
        }
    }
 
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;
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