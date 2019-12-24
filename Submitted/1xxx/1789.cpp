#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    int i = sqrt(2*n);
    while (1LL*i*(i+1)/2 <= n) i++;
    cout << --i;
}