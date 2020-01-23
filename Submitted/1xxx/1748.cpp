#include <iostream>
using namespace std;

int solve(int n) {
    int res = 0, base = (int)1e+8, cnt = 9;
    while (n) {
        if (n >= base) {
            res += cnt * (n - base + 1);
            n = base - 1;
        }
        base /= 10;
        cnt--;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}