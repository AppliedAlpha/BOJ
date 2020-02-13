#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r = 0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) r = (r+m) % i;
    cout << r+1;
    return 0;
}