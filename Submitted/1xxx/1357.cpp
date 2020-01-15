#include <iostream>
#include <string>
using namespace std;

int rv(const string& t) {
    int res = 0;
    for (int i=t.length()-1; i>=0; i--) res = res*10 + (t[i]-'0');
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << rv(to_string(rv(a) + rv(b)));
    return 0;
}