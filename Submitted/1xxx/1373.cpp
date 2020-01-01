#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int pos = 0;
    string str;
    cin >> str;
    if (str.length() % 3 == 1) {
        cout << str[0];
        pos++;
    }
    else if (str.length() % 3 == 2) {
        cout << (str[0]-'0')*2 + (str[1]-'0');
        pos += 2;
    }
    if (str.length() >= 3) {
        for (; pos <= str.length() - 2; pos += 3) {
            cout << (str[pos] - '0') * 4 + (str[pos + 1] - '0') * 2 + (str[pos + 2] - '0');
        }
    }
}