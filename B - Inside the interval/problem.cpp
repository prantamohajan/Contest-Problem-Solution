#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, a, b,minvalue,maxvalue;
    
    cin >> x >> a >> b;
    minvalue = min(a, b);
    maxvalue = max(a, b);

    if(x >= minvalue && x <= maxvalue)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}