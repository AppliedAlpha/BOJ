#include <iostream>
#define mod 1000000
#define period 1500000
using namespace std;
int fibo[1500000] = {0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l;
    cin >> l;
    for (int i=2; i<period; i++) {
        fibo[i] = fibo[i-2] + fibo[i-1];
        fibo[i] %= mod;
    }
    cout << fibo[l % period];
    return 0;
}