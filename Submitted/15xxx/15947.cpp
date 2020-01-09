#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y; //n = 14x+(y-1)
    cin >> n;
    x = n / 14;
    y = n % 14;
    if (y == 1 || y == 13) cout << "baby";
    if (y == 2 || y == 0) cout << "sukhwan";
    if (y == 5) cout << "very";
    if (y == 6) cout << "cute";
    if (y == 9) cout << "in";
    if (y == 10) cout << "bed";
    if (y == 3 || y == 7 || y == 11) {
        if (x >= 3) cout << "tu+ru*" << x+2;
        else {
            cout << "tu";
            for (int i=1; i<=x+2; i++) cout << "ru";
        }
    }
    if (y == 4 || y == 8 || y == 12) {
        if (x >= 4) cout << "tu+ru*" << x+1;
        else {
            cout << "tu";
            for (int i=1; i<=x+1; i++) cout << "ru";
        }
    }
    return 0;
}