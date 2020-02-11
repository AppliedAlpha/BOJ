#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[251];

string _add(string &x, string &y) {
    string res(max(x.size(), y.size()), '0');
    bool carry = false;
    for (int i=0; i<res.size(); i++) {
        int temp = carry;
        carry = false;
        if (i < x.size()) temp += x[x.size()-i-1] - '0';
        if (i < y.size()) temp += y[y.size()-i-1] - '0';
        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }
        res[res.size()-i-1] = temp + '0';
    }
    if (carry) res.insert(res.begin(), '1');
    return res;
} // from 10827

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    dp[0] = dp[1] = "1";
    dp[2] = "3";
    for (int i=3; i<251; i++) {
        auto temp = _add(dp[i-2], dp[i-2]);
        dp[i] = _add(dp[i-1], temp);
    }
    while (cin >> n) {
        cout << dp[n] << '\n';
    }
    return 0;
}