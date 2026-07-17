#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int counts = 0;
        
        while (n > 0) {
            counts += n / 5; 
            n = n / 5;       
        }
        
        cout << counts << endl;
    }
    
    return 0;
}