#include <iostream>
using namespace std;

int main() {
    double a[6], b[3], min = 1000.0f;
    for (double &i : a) cin >> i;
    for (int i = 0; i < 3; i++) {
        b[i] = a[i] / a[i + 3];
        if (min > b[i]) min = b[i];
    }
    for (int i = 0; i < 3; i++) printf("%.6lf ", a[i] - a[i + 3] * min);
}