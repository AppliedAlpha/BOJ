#include <iostream>
using namespace std;
int n, t, a[10003] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        a[t]++;
    }
    for (int i=1; i<=10000; i++) {
        if (a[i] != 0) for (int j=0; j<a[i]; j++) cout << i << '\n';
    }
}