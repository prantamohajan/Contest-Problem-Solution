#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int arr[3];
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        sort(arr, arr + 3);
        if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}