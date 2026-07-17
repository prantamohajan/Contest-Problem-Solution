#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
/**
 * Problem: C. Median Partition
 * Task: Maximize the number of odd-length subarrays with the same median.
 */
 
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    vector<int> sorted_a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    
    // 1. Identify the target median X.
    // The median of the whole array is the only candidate to maximize the partition.
    sort(sorted_a.begin(), sorted_a.end());
    int X = sorted_a[n / 2];
 
    // 2. DP to find maximum partition.
    // dp[i] = max subarrays for prefix of length i.
    // Initialize with a very small number to represent "impossible".
    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
 
    for (int i = 1; i <= n; i++) {
        int lt = 0, gt = 0, eq = 0;
        
        // Check every possible previous partition point j
        // such that a[j...i-1] is the last subarray.
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < X) lt++;
            else if (a[j] > X) gt++;
            else eq++;
 
            int L = i - j;
            
            // Condition 1: Subarray length must be odd.
            if (L % 2 == 1) {
                // Condition 2: Median of a[j...i-1] must be X.
                // This requires X to be present and 
                // elements strictly less/greater than X to be <= (L-1)/2.
                if (eq > 0 && 2 * lt < L && 2 * gt < L) {
                    if (dp[j] >= 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
    }
 
    // Output the maximum number of subarrays for the full length n.
    cout << dp[n] << "\n";
}
 
int main() {
    // Optimization for fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}