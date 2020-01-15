#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    for (auto & i : a) if (i == '6') i = '5';
    for (auto & i : b) if (i == '6') i = '5';
    cout << stoi(a) + stoi(b) << ' ';
    for (auto & i : a) if (i == '5') i = '6';
    for (auto & i : b) if (i == '5') i = '6';
    cout << stoi(a) + stoi(b);
    return 0;
}