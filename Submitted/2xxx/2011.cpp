#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    dp.resize(str.length());
    if (str[0] == '0') dp[0] = 0;
    else {
        dp[0] = 1;
        for (int i = 1; i < str.length(); i++) {
            int temp = stoi(str.substr(i - 1, 2));
            int prev = stoi(str.substr(i - 1, 1));
            int curr = stoi(str.substr(i, 1));
            if (temp >= 1 && temp <= 26) {
                if (curr != 0) dp[i] += dp[i - 1];
                if (prev != 0) dp[i] += (i >= 2 ? dp[i - 2] : 1);
                dp[i] %= 1000000;
            } else dp[i] = dp[i - 1];
        }
    }
    cout << dp[str.length()-1];
    return 0;
}