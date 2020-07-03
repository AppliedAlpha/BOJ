#include <iostream>
using namespace std;
typedef long long i64;

bool solve() {
    i64 n;
    cin >> n;
    while (n != 1) {
        if (n % 2) return false;
        n /= 2;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << solve();
    return 0;
}