#include <iostream>
using namespace std;
int d1[32], d2[32], col[16], n, res = 0;

//well-known n-queen problem
void search(int x) {
    if (x == n) {
        res++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (col[i] || d1[i+x] || d2[i-x+n-1]) continue;
        col[i] = d1[i+x] = d2[i-x+n-1] = 1;
        search(x+1);
        col[i] = d1[i+x] = d2[i-x+n-1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    search(0);
    cout << res;
    return 0;
}