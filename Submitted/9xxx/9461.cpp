#include <iostream>
using namespace std;
long long a[101];

long long solve(int k) {
    if (a[k]) return a[k];
    for (int i=6; i<=k; i++) a[i] = a[i-1] + a[i-5];
    return a[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    a[1] = a[2] = a[3] = 1;
    a[4] = a[5] = 2;
    while (n--) {
        cin >> k;
        cout << solve(k) << '\n';
    }
}