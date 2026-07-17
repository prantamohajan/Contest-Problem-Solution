#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;

        int count = 0;

        for(int i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                if(i * i == x)
                    count++;        
                else
                    count += 2;     
            }
        }

        cout << count << endl;
    }

    return 0;
}