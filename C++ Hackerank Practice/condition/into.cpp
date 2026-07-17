#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string arr[] = {
        "zero","one","two","three","four",
        "five","six","seven","eight","nine"
    };

    if(n >= 1 && n <= 9){
        cout << arr[n];
    }
    else{
        cout << "Greater than 9";
    }

    return 0;
}