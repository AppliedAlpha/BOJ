#include <iostream>
using namespace std;
int a[51], b[51];

void solve(int n) {
    if (n == 1) {
        cout << 'A';
        return;
    }
    else if (n == 2) {
        cout << 'A';
        return;
    }
    else if (n == 3) {
        for (int i=0; i<2; i++) b[i] = a[i+1]-a[i];
        if (b[1] % b[0]) {
            cout << 'B';
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    solve(n);
}