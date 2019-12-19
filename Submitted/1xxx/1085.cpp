#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int x, y, bx, by;
    cin >> x >> y >> bx >> by;
    int minx = (bx - x <= x ? bx-x : x);
    int miny = (by - y <= y ? by-y : y);
    cout << (minx <= miny ? minx : miny);
}