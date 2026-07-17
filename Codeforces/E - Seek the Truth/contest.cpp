
#include <iostream>
 
using namespace std;
 
typedef unsigned long long ull;
 
void solve() {
    int n;
    if (!(cin >> n)) return;
 
    ull total_mask = 0;
    for (int i = 0; i < n; i++) total_mask |= (1ULL << i);
 
    // Initial element choice
    cout << 0 << endl;
 
    // First query to distinguish k=1 from k=2,3
    cout << "I 0" << endl;
    int size_s;
    if (!(cin >> size_s)) exit(0);
    if (size_s == -1) exit(0);
 
    if (size_s == 1) {
        cout << "I " << total_mask << endl;
        if (!(cin >> size_s)) exit(0);
        if (size_s == -1) exit(0);
 
        // Binary search for c in the set S = {0, c}.
        ull low = 1, high = total_mask;
        while (low < high) {
            ull mid = low + (high - low + 1) / 2;
            cout << "Q " << mid << endl;
            int res;
            if (!(cin >> res)) exit(0);
            if (res == -1) exit(0);
            if (res >= 1) low = mid; // c is in S and c >= mid
            else high = mid - 1;
        }
        cout << "A 1 " << low << endl;
    } else {
        // Case k=2 or 3: f(0)=c, so S = {0, c}.
        // Binary search for c in the set S = {0, c}.
        ull low = 1, high = total_mask;
        while (low < high) {
            ull mid = low + (high - low + 1) / 2;
            cout << "Q " << mid << endl;
            int res;
            if (!(cin >> res)) exit(0);
            if (res == -1) exit(0);
            if (res >= 1) low = mid;
            else high = mid - 1;
        }
        ull c = low;
 
        if (c == total_mask) {
            // Distinguish k=2 and k=3 by inserting f(1).
            cout << "I 1" << endl;
            if (!(cin >> size_s)) exit(0);
            if (size_s == -1) exit(0);
            // If k=2, f(1) = 1 | total_mask = total_mask, size remains 2.
            // If k=3, f(1) = 1 ^ total_mask = total_mask - 1, size becomes 3.
            if (size_s == 2) {
                cout << "A 2 " << c << endl;
            } else {
                cout << "A 3 " << c << endl;
            }
        } else {
            // Distinguish k=2 and k=3 by inserting f(total_mask).
            cout << "I " << total_mask << endl;
            if (!(cin >> size_s)) exit(0);
            if (size_s == -1) exit(0);
 
            // Check if total_mask was added to the set.
            cout << "Q " << total_mask << endl;
            int res;
            if (!(cin >> res)) exit(0);
            if (res == -1) exit(0);
            // If k=2, total_mask | c = total_mask.
            // If k=3, total_mask ^ c = ~c < total_mask (as c >= 1).
            if (res >= 1) {
                cout << "A 2 " << c << endl;
            } else {
                cout << "A 3 " << c << endl;
            }
        }
    }
}
 
int main() {
    // Basic setup for I/O efficiency.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}