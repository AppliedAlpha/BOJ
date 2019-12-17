#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string &a, string &b) {
    string result(max(a.size(), b.size()), '0');
    bool carry = false;
    for (int i=0; i<result.size(); i++) {
        int temp = carry;
        carry = false;
        if (i < a.size()) temp += a[a.size()-i-1] - '0';
        if (i < b.size()) temp += b[b.size()-i-1] - '0';
        if (temp >= 10) {
            temp -= 10;
            carry = true;
        }
        result[result.size()-i-1] = temp + '0';
    }
    if (carry) result.insert(result.begin(), '1');
    return result;
}

string solve(int n) {
    string a = "0", b = "1";
    int i = 0;
    while (++i <= n) {
        auto c = add(a, b);
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n) << '\n';
}