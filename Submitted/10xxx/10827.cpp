#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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
}

string _mul(string &x, string &y) {
    string res = "0";
    for (int i=0; i<y.size(); i++) {
        string line(x);
        int carry = 0;
        for (int j=x.size()-1; j>=0; j--) {
            int temp = carry;
            carry = 0;
            temp += (x[j]-'0') * (y[y.size()-i-1]-'0');
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }
        if (carry > 0) line.insert(line.begin(), carry + '0');
        line += string(i, '0');
        res = _add(res, line);
    }
    return res;
}

string _power(string &a, int b) {
    if (b == 1) return a;
    string res = _power(a, b/2);
    if (b & 1) {
        res = _mul(res, res);
        return _mul(res, a);
    }
    else return _mul(res, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int b;
    cin >> a >> b;
    string::iterator finder = find(a.begin(), a.end(), '.');
    int idx = 0;
    if (finder != a.end()) {
        idx = a.end() - finder - 1;
        a.erase(finder);
    }
    idx *= b;
    string res = _power(a, b);
    if (idx > 0) res.insert(res.end() - idx, '.');
    cout << res;
    return 0;
}