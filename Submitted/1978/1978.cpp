#include <iostream>
#include <cmath>
using namespace std;
int s = 0, n, t, j;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        if (t == 1) continue;
        if (t/2 == 1) {
            s++;
            continue;
        }
        if (!(t%2)) continue;
        //5 이상
        for (j=3; j<=sqrt(t); j += 2) {
            if (!(t%j)) goto f;
        }
        s++;
        f:
        continue;
    }
    cout << s;
    return 0;
}