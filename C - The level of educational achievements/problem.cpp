#include <iostream>
using namespace std;

int main() {
    int grade;
    cin >> grade;
    if(grade >= 1 && grade <= 3)
        cout << "Initial";
    else if(grade <= 6)
        cout << "Average";
    else if(grade <= 9)
        cout << "Sufficient";
    else
        cout << "High";
    
    return 0;
}