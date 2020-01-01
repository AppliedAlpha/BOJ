#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, di, tmp, sum = 0;
    cin >> a >> b >> di;
    for (int i=di-1; i>=0; i--) {
        cin >> tmp;
        sum += tmp * int(pow(a, i));
    }
    int d = b;
    while (d * b <= sum) d *= b;
    while (d) {
        cout << sum / d << ' ';
        sum %= d;
        d /= b;
    }
}