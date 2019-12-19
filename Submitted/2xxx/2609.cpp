#include <iostream>
using namespace std;
int a, b;

int gcd(int x, int y) {
    int z;
    while (x % y) {
        z = x % y;
        x = y;
        y = z;
    }
    return y;
}

int main() {
    cin >> a >> b;
    int c = gcd(a, b);
    cout << c << "\n" << a * b / c;
}