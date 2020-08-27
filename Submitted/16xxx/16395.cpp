#include <iostream>
#include <string>
#include <vector>
using namespace std;
string dp[101][101];

string sum(string a, string b) {
    string res, tmp;
    if (a.length() > b.length()) {
        for (int i=1; i<=a.length()-b.length(); i++) tmp += '0';
        b = tmp + b;
    }
    if (a.length() < b.length()) {
        for (int i=1; i<=b.length()-a.length(); i++) tmp += '0';
        a = tmp + a;
    }
    a = '0' + a;
    b = '0' + b;
    vector<int> v(a.length(), 0);
    for (int i=a.length()-1; i>=1; i--) {
        v[i] += (a[i] - '0') + (b[i] - '0');
        if (v[i] >= 10) {
            v[i] -= 10;
            v[i-1]++;
        }
    }
    if (v[0] != 0) res.append(to_string(v[0]));
    for (int i=1; i<a.length(); i++) res.append(to_string(v[i]));
    return res;
}

string c(int n, int r) {
    if (n == r || r == 0) return "1";
    string& res = dp[n][r];
    if (!res.empty()) return res;
    res = sum(c(n-1, r-1), c(n-1, r));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    cout << c(n-1, r-1);
    return 0;
}