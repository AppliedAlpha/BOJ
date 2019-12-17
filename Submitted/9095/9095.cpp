#include <iostream>
using namespace std;

//solve(x) = solve(x-1) + ... + solve(x-3);

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, solve[12] = {0, };
    cin >> n;
    solve[0] = 1;
    for (int i=1; i<=11; i++) {
        for (int j=1; j<=3; j++) {
            if (i-j >= 0) solve[i] += solve[i-j];
        }
    }
    for (int i=0; i<n; i++) {
        cin >> k;
        cout << solve[k] << '\n';
    }
}