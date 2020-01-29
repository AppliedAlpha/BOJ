#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b, tmp;
    cin >> a >> b;
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
    if (v[0] != 0) cout << v[0];
    for (int i=1; i<a.length(); i++) cout << v[i];
}