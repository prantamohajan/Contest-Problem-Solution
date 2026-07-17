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
        
        vector<long long> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        vector<long long> mins(n), maxs(n);
        long long sum_maxs = 0;
        long long max_min_val = -1;
        long long second_min_val = -1;
        int count_max = 0;
        
        for(int i = 0; i < n; i++) {
            mins[i] = min(a[i], b[i]);
            maxs[i] = max(a[i], b[i]);
            sum_maxs += maxs[i];
            
            long long mi = mins[i];
            if(mi > max_min_val) {
                second_min_val = max_min_val;
                max_min_val = mi;
                count_max = 1;
            } else if(mi == max_min_val) {
                count_max++;
            } else if(mi > second_min_val) {
                second_min_val = mi;
            }
        }
        
        long long best = max_min_val;
        
        for(int j = 0; j < n; j++) {
            long long max_other;
            if(n == 1) {
                max_other = 0;
            } else if(mins[j] < max_min_val || count_max >= 2) {
                max_other = max_min_val;
            } else {
                max_other = second_min_val;
            }
            
            long long M = max(maxs[j], max_other);
            long long extra = maxs[j] - mins[j];
            long long curr = M - extra;
            
            if(curr > best) {
                best = curr;
            }
        }
        
        long long answer = sum_maxs + best;
        cout << answer << '\n';
    }
    
    return 0;
}