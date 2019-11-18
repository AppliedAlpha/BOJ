#include <iostream>
using namespace std;

int main() {
    int x, y, t, i, j, s = 0;
    cin >> x >> y;
    for (i=1; i<=45; i++) {
        if (x >= i*(i-1)/2 + 1 && x <= i*(i+1)/2) break;
    }
    for (t=x; t<=y; t++) {
        for (j=i; j<=45; j++) {
            if (t >= j*(j-1)/2 + 1 && t <= j*(j+1)/2) {
                s += j;
                break;
            }
        }
    }
    cout << s;
}