#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
 
    vector<pair<long long, long long>> path_a;
    long long curr_a = a;
    long long steps_a = 0;
    while (true) {
        path_a.push_back({curr_a, steps_a});
        if (curr_a == 0) break;
        curr_a /= x;
        steps_a++;
    }
 
    vector<pair<long long, long long>> path_b;
    long long curr_b = b;
    long long steps_b = 0;
    while (true) {
        path_b.push_back({curr_b, steps_b});
        if (curr_b == 0) break;
        curr_b /= x;
        steps_b++;
    }
 
    long long min_ops = -1;
 
    for (auto& p_a : path_a) {
        for (auto& p_b : path_b) {
            long long va = p_a.first;
            long long sa = p_a.second;
            long long vb = p_b.first;
            long long sb = p_b.second;
 
            long long ops = sa + sb + abs(va - vb);
            if (min_ops == -1 || ops < min_ops) {
                min_ops = ops;
            }
        }
    }
 
    cout << min_ops << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}