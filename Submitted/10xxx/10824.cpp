#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int input[4];
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    string tmp1 = to_string(input[0]) + to_string(input[1]);
    string tmp2 = to_string(input[2]) + to_string(input[3]);

    cout << stol(tmp1) + stol(tmp2);
    return 0;
}