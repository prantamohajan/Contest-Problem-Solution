#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PrefixSumInfo {
    long long value;
    int original_index;
};
 
// Sort descending to pair largest prefix sums with smallest permutation values (1, 2, ...)
bool comparePrefixSums(const PrefixSumInfo& a, const PrefixSumInfo& b) {
    if (a.value != b.value) {
        return a.value > b.value;
    }
    return a.original_index < b.original_index;
}
 
void solve() {
    int n;
    if (!(cin >> n)) return;
 
    // IMPORTANT: Read all n integers to clear the input buffer
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    // Calculate Prefix Sums P_0 to P_{n-1}
    // P_k is the weight for the value at position k+1 (p_{k+1})
    vector<PrefixSumInfo> p_sums(n);
    long long current_p = 0;
    
    p_sums[0] = {0, 0}; // P_0 = 0
    for (int i = 0; i < n - 1; i++) {
        current_p += a[i];
        p_sums[i + 1] = {current_p, i + 1};
    }
 
    // Sort prefix sums descending
    sort(p_sums.begin(), p_sums.end(), comparePrefixSums);
 
    // Assign values 1 to n based on the sorted order
    vector<int> p_result(n);
    for (int i = 0; i < n; i++) {
        p_result[p_sums[i].original_index] = i + 1;
    }
 
    // Output the resulting permutation
    for (int i = 0; i < n; i++) {
        cout << p_result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}
 
int main() {
    // Standard speed-up for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}