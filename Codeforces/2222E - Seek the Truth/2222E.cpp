#include <iostream>
using namespace std;
typedef unsigned long long ull;
void solve() {
    int n;
    if (!(cin >> n)) return;

    ull total_mask = 0;
    for (int i = 0; i < n; i++) total_mask |= (1ULL << i);
    cout << 0 << endl;
    cout << "I 0" << endl;
    int size_s;
    if (!(cin >> size_s)) exit(0);
    if (size_s == -1) exit(0);

    if (size_s == 1) {
        cout << "I " << total_mask << endl;
        if (!(cin >> size_s)) exit(0);
        if (size_s == -1) exit(0);
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
        cout << "A 1 " << low << endl;
    } else {
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
            cout << "I 1" << endl;
            if (!(cin >> size_s)) exit(0);
            if (size_s == -1) exit(0);

            if (size_s == 2) {
                cout << "A 2 " << c << endl;
            } else {
                cout << "A 3 " << c << endl;
            }
        } else {
            cout << "I " << total_mask << endl;
            if (!(cin >> size_s)) exit(0);
            if (size_s == -1) exit(0);
            cout << "Q " << total_mask << endl;
            int res;
            if (!(cin >> res)) exit(0);
            if (res == -1) exit(0);
            if (res >= 1) {
                cout << "A 2 " << c << endl;
            } else {
                cout << "A 3 " << c << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}