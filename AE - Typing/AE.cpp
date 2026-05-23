#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int i = 0;
    vector<int> ans;

    for (int j = 0; j < T.size(); j++) {
        if (i < S.size() && S[i] == T[j]) {
            ans.push_back(j + 1); 
            i++;
        }
    }

    for (int x : ans) cout << x << " ";
}