#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct PrefixSumInfo {
    long long value;
    int original_index;
};

bool comparePrefixSums(const PrefixSumInfo& a, const PrefixSumInfo& b) {
    if (a.value != b.value) {
        return a.value > b.value;
    }
    return a.original_index < b.original_index;
}
void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<PrefixSumInfo> p_sums(n);
    long long current_p = 0;
    
    p_sums[0] = {0, 0}; // P_0 = 0
    for (int i = 0; i < n - 1; i++) {
        current_p += a[i];
        p_sums[i + 1] = {current_p, i + 1};
    }
    sort(p_sums.begin(), p_sums.end(), comparePrefixSums);
    vector<int> p_result(n);
    for (int i = 0; i < n; i++) {
        p_result[p_sums[i].original_index] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << p_result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}