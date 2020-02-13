#include <iostream>
#include <algorithm>
using namespace std;

bool notPrime[7400000] = {0, 1, };

void eratos() {
    for (int i=2; i*i<7400000; i++) {
        if (!notPrime[i]) {
            for (int j=i+i; j<7400000; j+=i) {
                notPrime[j] = true;
            }
        }
    }
}

int solve(int n) {
    if (n == 1) return 2;
    int check = 1;
    for (int i=3; i<7400000; i+=2) {
        if (!notPrime[i]) check++;
        if (check == n) return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    eratos();
    cout << solve(n);
    return 0;
}