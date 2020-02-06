#include <iostream>
using namespace std;

int solve(int n) {
    if (!(n % 2)) return n/2;
    else {
        for (int i=3; i*i<=n; i+=2) {
            if (!(n % i)) return n/i*(i-1);
        }
    }
    return n-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}