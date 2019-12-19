#include <iostream>
using namespace std;

int fact(int a) {
    if (a <= 1) return 1;
    else {
        int b = 1;
        for (int i=2; i<=a; i++) {
            b *= i;
        }
        return b;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << fact(n)/(fact(k)*fact(n-k));
}