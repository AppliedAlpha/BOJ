#include <iostream>
#include <cmath>
using namespace std;

int solve(int n) {
    if (n <= 9) return n;
    int c = (int) log10(n);
    int tt = n;
    for (int i=1; i<=c; i++) {
        double t = (double)tt / pow(10, i);
        tt = (int)(round(t) * pow(10, i));
    }
    return tt;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}