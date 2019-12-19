#include <iostream>
using namespace std;

int main() {
    int a, c = 99;
    cin >> a;
    if (a < 100) cout << a;
    else {
        int ax, ay, az;
        for (int i=100; i<=a; i++) {
            ax = i / 100;
            ay = i / 10 % 10;
            az = i % 10;
            if (ax - ay == ay - az) c++;
        }
        cout << c;
    }
    return 0;
}