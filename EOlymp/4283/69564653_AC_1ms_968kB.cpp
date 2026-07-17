#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;

    for (long long i = 1; i <= n; ) {
        long long val = n / i;             
        long long last = n / val;         

        ans += val * (last - i + 1);      
        i = last + 1;                   
    }

    cout << ans << endl;
}