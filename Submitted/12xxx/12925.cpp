#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
ll c[211];
int n, x, res;

// ~= 12728
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    c[1] = 6;
    c[2] = 28;
    for (int i=3; i<=210; i++) {
        c[i] = (c[i-1] * 6 - c[i-2] * 4) + 10000;
        c[i] %= 1000;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        res = (x > 104 ? c[(x-4) % 100 + 4] : c[x]);
        cout << "Case #" << i << ": ";
        cout.width(3);
        cout.fill('0');
        cout << (res + 999) % 1000 << '\n';
    }
    return 0;
}
