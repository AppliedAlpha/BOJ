#include <iostream>
using namespace std;

int solve(int n) {
    int max = 1, a[10] = {0, };
    if (!n) return 1;
    while (n) {
        a[n % 10]++;
        n /= 10;
    }
    a[9] += a[6];
    a[9] = a[9] / 2 + (a[9] % 2);
    a[6] = 0;
    for (auto i : a) if (i >= max) max = i;
    return max;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}