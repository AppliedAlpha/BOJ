#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    cout << min(min(a, b), c) + min(x, y) - 50;
    return 0;
}