#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, t, a[41];
    cin >> n;
    a[0] = 0;
    a[1] = 1;
    for (int i=2; i<41; i++) a[i] = a[i-2] + a[i-1];
    for (int i=0; i<n; i++) {
        cin >> t;
        if (t == 0) cout << "1 0\n";
        else cout << a[t-1] << " " << a[t] << '\n';
    }
}