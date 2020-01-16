#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void hanoi(int n, int from, int to, int temp) {
    if (n == 1) cout << from << ' ' << to << '\n';
    else {
        hanoi(n-1, from, temp, to);
        cout << from << ' ' << to << '\n';
        hanoi(n-1, temp, to, from);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    int n;
    cin >> n;
    //get 2^n - 1 (bigint)
    string s = to_string(pow(2, n));
    int idx = s.find('.');
    s = s.substr(0, idx);
    s[s.length() - 1] -= 1;
    cout << s << '\n';
    if (n <= 20) hanoi(n, 1, 3, 2);
    return 0;
}