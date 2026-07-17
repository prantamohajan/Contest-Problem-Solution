#include <iostream>
using namespace std;
int main() {
    string text;
    getline(cin, text);
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }
    cout << text << endl;
    return 0;
}