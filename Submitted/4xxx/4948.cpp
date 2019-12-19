#include <iostream>

using namespace std;
bool isPrime[300001];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        int cnt = 0;
        for (int i = 2; i <= 2 * n; i++)
            isPrime[i] = true;
        isPrime[1] = false;
        for (int i = 2; i * i <= 2 * n; i++) {
            if (!isPrime[i]) continue;
            for (int j = 2 * i; j <= 2 * n; j += i) isPrime[j] = false;
        }
        for (int i = n+1; i <= 2 * n; i++)
            if (isPrime[i]) cnt++;
        cout << cnt << '\n';
        cin >> n;
    }
}