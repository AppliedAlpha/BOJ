#include <iostream>
using namespace std;

int solve(int n) {
    int arr[11] = {0, 1, 2, 3, 5, 8, };
    if (n <= 5) return arr[n];
    else {
        int a = 5, b = 8, c;
        for (int i=6; i<=n; i++) {
            c = (a + b) % 10;
            a = b % 10;
            b = c % 10;
        }
        return b;
    }
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}