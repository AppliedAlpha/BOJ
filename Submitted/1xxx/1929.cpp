#include <iostream>
#include <cmath>
using namespace std;
bool isPrime[1000001]; //true: prime, false: not prime

int main() {
    int m, n;
    cin >> m >> n;
    for (int i=2; i<=n; i++) isPrime[i] = true;
    isPrime[1] = false;
    for (int i=2; i<=sqrt(n); i++) {
        if (!isPrime[i]) continue;
        for (int j=2*i; j<=n; j += i) isPrime[j] = false;
    }
    for (int i=m; i<=n; i++) if (isPrime[i]) cout << i << "\n";
}

