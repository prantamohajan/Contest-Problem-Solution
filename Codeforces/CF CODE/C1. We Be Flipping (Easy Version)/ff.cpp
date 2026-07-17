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
        
        vector<long long> a(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        vector<int> p(n+2, 0);
        for(int i = 1; i <= n; i++) {
            p[i] = (a[i] > 0 ? 1 : 0);
        }
        

        vector<int> ops;
        for(int j = 1; j <= n; j++) {
            int next_p = (j < n ? p[j+1] : 0);
            if(p[j] != next_p) {
                ops.push_back(j);
            }
        }
        
        reverse(ops.begin(), ops.end());
        
        // Output
        cout << ops.size() << '\n';
        for(int i = 0; i < (int)ops.size(); i++) {
            cout << ops[i] << (i + 1 == (int)ops.size() ? '\n' : ' ');
        }
        
        if(ops.empty()) {
            cout << '\n';
        }
    }
    
    return 0;
}