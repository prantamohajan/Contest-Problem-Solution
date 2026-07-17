
#include <iostream>
using namespace std;

int main() {
    int T, M;
    if (!(cin >> T)) return 0;
    for (int i = 1; i <= T; ++i) {
        cin >> M;
        string grade;
        if (M >= 80 && M <= 100) {
            grade = "A+";
        } else if (M >= 75 && M <= 79) {
            grade = "A";
        } else if (M >= 70 && M <= 74) {
            grade = "A-";
        } else if (M >= 65 && M <= 69) {
            grade = "B+";
        } else if (M >= 60 && M <= 64) {
            grade = "B";
        } else if (M >= 55 && M <= 59) {
            grade = "B-";
        } else if (M >= 50 && M <= 54) {
            grade = "C";
        } else if (M >= 45 && M <= 49) {
            grade = "D";
        } else {
            grade = "F";
        }
        cout << "Case " << i << ": " << grade << endl;
    }
    
    return 0;
}