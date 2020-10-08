#include <iostream>
#include <numeric>
using namespace std;
int up[51], down[51];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> up[i] >> down[i];
        int div = gcd(up[i], down[i]);
        up[i] /= div;
        down[i] /= div;
    }

    int resDown = down[0];
    for (int i=1; i<n; i++)
        resDown = lcm(resDown, down[i]);
    for (int i=0; i<n; i++) {
        int mul = resDown / down[i];
        up[i] *= mul;
        down[i] *= mul;
    }

    // for (int i=0; i<n; i++) cout << up[i] << ' ' << down[i] << '\n';

    int resUp = up[0];
    for (int i=1; i<n; i++)
        resUp = gcd(resUp, up[i]);

    int div = gcd(resUp, resDown);
    resUp /= div;
    resDown /= div;

    cout << resUp << ' ' << resDown;
    return 0;
}