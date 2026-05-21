#include<iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count[5] = {0};
    count[a]++;
    count[b]++;
    count[c]++;
    count[d]++;

    int ans = 0;

    for(int i = 1; i <= 4; i++) {
        ans += count[i] / 2;
    }

    cout << ans;

    return 0;
}