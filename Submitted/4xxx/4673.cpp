#include <iostream>
#include <cmath>
using namespace std;

int dn(int n) {
    int res = n;
    int c = (int)log10(n); //100 -> 2, 300 -> 2.xx
    for (int i=0; i<c; i++) {
        int div = (int)round(pow(10, c-i));
        res += (n / div);
        n %= div;
    }
    return res + n;
}

int main() {
    int k;
    bool exist[10001] = {false, };
    for (int i=1; i<=10000; i++) {
        if (!exist[i]) {
            cout << i << '\n';
            k = dn(i);
            while (k <= 10000) {
                exist[k] = true;
                k = dn(k);
            }
        }
    }
}