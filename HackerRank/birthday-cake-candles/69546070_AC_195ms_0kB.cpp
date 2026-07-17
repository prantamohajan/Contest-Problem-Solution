
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    int max_val = 0;
    int count = 0;
    for (int i = 0; i < candles.size(); i++) {
        if (candles[i] > max_val) {
            max_val = candles[i];
        }
    }
    for (int i = 0; i < candles.size(); i++) {
        if (candles[i] == max_val) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> candles(n);
    for (int i = 0; i < n; i++) {
        cin >> candles[i];
    }

    cout << birthdayCakeCandles(candles) << endl;
    return 0;
}