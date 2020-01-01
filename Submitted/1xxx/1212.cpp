#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int pos = 0;
    string str;
    cin >> str;
    int c = str[0] - '0';
    str = str.substr(1);
    if (c/4) cout << 1 << (c-4)/2 << c%2;
    else if (c/2) cout << c/2 << c%2;
    else cout << c;
    for (auto a : str) {
        int tmp = a - '0';
        cout << tmp/4 << (tmp%4)/2 << tmp%2;
    }
}