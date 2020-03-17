#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char ch[10];
    cin >> ch;
    cout << (int)strtol(ch, nullptr, 16);
    return 0;
}