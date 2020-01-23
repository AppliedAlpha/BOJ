#include <iostream>
#define m 1000000009;
using namespace std;
int solve[1000003] = {0, };

//solve(x) = solve(x-1) + ... + solve(x-3);

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n;
    solve[0] = 1;
    for (int i=1; i<=1000001; i++) {
        for (int j=1; j<=3; j++) {
            if (i-j >= 0) solve[i] = (solve[i] + solve[i-j]) % m;
        }
    }
    while (n--) {
        cin >> k;
        cout << solve[k] << '\n';
    }
}