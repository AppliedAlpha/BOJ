#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, tmp, d = 1, sum = 0;
    string str;
    cin >> str >> b;
    for (int i=str.length()-1; i>=0; i--) {
        if (str[i] >= '0' && str[i] <= '9') tmp = str[i]-'0';
        else tmp = str[i]-'A'+10;
        sum += tmp * d;
        d *= b;
    }
    cout << sum;
}