#include <iostream>
using namespace std;
int a[6], res = 0;

// inspired by jh05013
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i=1; i<=5; i++) cin >> a[i];
    while (a[1] + a[2] + a[3] + a[4] + a[5]) {
        res++;
        int area = 5;
        for (int i=5; i>=1; i--) {
            while (a[i] && area >= i) {
                area -= i;
                a[i]--;
            }
        }
    }
    cout << res;
    return 0;
}



#include <iostream>
using namespace std;
int a[6], res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i=1; i<=5; i++) cin >> a[i];
    res += (a[5] + a[4]);
    a[1] -= a[4];
    a[5] = 0;
    a[4] = 0;
    if (a[1] < 0) a[1] = 0;
    int tmp = (a[2] >= a[3] ? a[3] : a[2]);
    a[2] -= tmp;
    a[3] -= tmp;
    res += tmp;
    if (a[3] > 0) { //a[2] = 0
        res += a[3];
        a[1] -= 2 * a[3];
        if (a[1] < 0) a[1] = 0;
        a[3] = 0;
    }
    if (a[2] > 0) { //a[3] = 0;
        while (a[2] >= 2) {
            res++;
            a[2] -= 2;
            a[1]--;
        }
        if (a[2] == 1) {
            res++;
            a[2]--;
            a[1] -= 3;
        }
        if (a[1] < 0) a[1] = 0;
    }
    res += (a[1]/5) + (a[1] % 5 ? 1 : 0);
    cout << res;
    return 0;
}