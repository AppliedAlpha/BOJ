#include <iostream>
using namespace std;
bool notPrime[1002];

int solve(int n, int k) {
    int res = 0;
    notPrime[1] = true;
    for (int i=2; i<=n; i++) {
        if (notPrime[i]) continue;
        res++;
        if (res == k) return i;
        for (int j=2*i; j<=n; j+=i) {
            if (notPrime[j]) continue;
            notPrime[j] = true;
            res++;
            if (res == k) return j;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}