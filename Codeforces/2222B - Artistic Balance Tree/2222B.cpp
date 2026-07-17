#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<ll> a(n);
    ll total_sum = 0;
    vector<ll> odd_pool, even_pool;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
        if ((i + 1) % 2 != 0) {
            odd_pool.push_back(a[i]);
        } else {
            even_pool.push_back(a[i]);
        }
    }
 
    int m_odd = 0, m_even = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x % 2 != 0) m_odd++;
        else m_even++;
    }
 
    sort(odd_pool.rbegin(), odd_pool.rend());
    sort(even_pool.rbegin(), even_pool.rend());
 
    ll marked_sum = 0;
 
    // Process Odd Pool
    if (m_odd > 0 && !odd_pool.empty()) {
        marked_sum += odd_pool[0]; // Must mark at least one
        int can_mark = min((int)odd_pool.size(), m_odd);
        for (int i = 1; i < can_mark; i++) {
            if (odd_pool[i] > 0) {
                marked_sum += odd_pool[i];
            } else {
                break; // Remaining are non-positive
            }
        }
    }
 
    // Process Even Pool
    if (m_even > 0 && !even_pool.empty()) {
        marked_sum += even_pool[0]; // Must mark at least one
        int can_mark = min((int)even_pool.size(), m_even);
        for (int i = 1; i < can_mark; i++) {
            if (even_pool[i] > 0) {
                marked_sum += even_pool[i];
            } else {
                break;
            }
        }
    }
 
    cout << total_sum - marked_sum << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}