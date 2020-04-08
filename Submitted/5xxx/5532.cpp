#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    cout << l - max(a/c + (bool)(a%c), b/d + (bool)(b%d));
    return 0;
}