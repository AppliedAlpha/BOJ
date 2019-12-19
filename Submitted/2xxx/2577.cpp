#include <iostream>
using namespace std;
int a, b, c;
int t[10] = {0, };

int main() {
    cin >> a >> b >> c;
    int d = a * b * c;
    while (d != 0) {
        t[d % 10]++;
        d /= 10;
    }
    for (int i : t) cout << i << "\n";
}