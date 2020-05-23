#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c[100005], _prev = 2147483646, temp;
long long res = 0LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0; i<n-1; i++) cin >> c[i];
    for (int i=0; i<n-1; i++) {
        cin >> temp;
        _prev = min(_prev, temp);
        res += (long long)_prev * c[i];
    }
    cout << res;
    return 0;
}
