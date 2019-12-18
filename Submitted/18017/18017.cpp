#include <iostream>
#define c 299792458
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout.precision(10);
    cout << fixed << (a + b) / (1 + ((a / c) * (b / c)));
}