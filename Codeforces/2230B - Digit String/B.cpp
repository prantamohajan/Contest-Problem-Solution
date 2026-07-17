#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        string s;
        cin >> s;
        int n = s.size();
        
        vector<int> pref2(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref2[i] = pref2[i-1];
            if(s[i-1] == '2') pref2[i]++;
        }
        
        vector<int> suff13(n+1, 0);
        suff13[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            suff13[i] = suff13[i+1];
            if(s[i] == '1' || s[i] == '3') suff13[i]++;
        }
        
        int max_keep = 0;
        for(int i = 0; i <= n; i++) {
            max_keep = max(max_keep, pref2[i] + suff13[i]);
        }
        
       
        max_keep = max(max_keep, suff13[0]);
        
        cout << (n - max_keep) << '\n';
    }
    return 0;
}