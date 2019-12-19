#include <iostream>
#include <cmath>
using namespace std;
int s = 0, n, m, t, j;
bool first = false;

int main() {
    cin >> n >> m;
    for (int i=n; i<=m; i++) {
        if (i == 1) continue;
        if (i/2 == 1) {
            s += i;
            if (!first) {
                t = i;
                first = true;
            }
            continue;
        }
        if (!(i%2)) continue;
        //5 이상
        for (j=3; j<=sqrt(i); j += 2) {
            if (!(i%j)) goto f;
        }
        s += i;
        if (!first) {
            t = i;
            first = true;
        }
        f:
        continue;
    }
    cout << ((s != 0) ? s : -1) << '\n';
    if (first) cout << t;
    return 0;
}