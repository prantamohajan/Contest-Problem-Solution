#include <iostream> 
#include <string>
using namespace std;
int main() {
    int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    int m, d;
    while (cin >> m >> d && (m != 0 || d != 0)) {
        int totalDays = 0;
        for (int i = 0; i < m - 1; i++) {
            totalDays += daysInMonth[i];
        }
        totalDays += (d - 1);
        cout << week[totalDays % 7] << endl;
    }
    return 0;
}