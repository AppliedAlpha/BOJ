#include <iostream>
#include <cmath>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    bool *a = new bool[m+1];
    for (int i=2; i<=sqrt(m); i++) {
        for (int j=n; j<=m; j++) {
            if (!(j%i)) a[j] = false;
        }
    }
    a[1] = false;
    a[2] = true;
    a[3] = true;
    for (int i=n; i<=m; i++) if (a[i]) cout << i << '\n';
}