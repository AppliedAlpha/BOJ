#include <iostream>
#include <string>
using namespace std;
int t;
char a[1000003], s[1000003];
/* I HAVE A PEN
 * I HAVE AN APPLE
 * UHH!
 * PPAPPAPPAP */

bool ppap() {
    if (t < 4) return false;
    return (s[t - 4] == 'P' && s[t - 3] == 'P' && s[t - 2] == 'A' && s[t - 1] == 'P');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    cin >> a;
    for (int i=0; a[i]; i++) {
        s[t++] = a[i];
        while (ppap()) {
            t -= 4;
            s[t++] = 'P';
        }
    }
    cout << ((t == 1 && s[0] == 'P') ? "PPAP" : "NP");
    return 0;
}