#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
int _xor[200003], _xor_value[200003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, type, x, y, d;
    cin >> n >> m;
    _xor_value[1] = 1;
    for (int i=2; i<=n; i++) {
        cin >> _xor[i];
        _xor_value[i] = _xor_value[i-1] ^ _xor[i];
    }
    for (int i=0; i<m; i++) {
        cin >> type;
        if (!type) {
            cin >> x >> y;
            cout << int(_xor_value[x] ^ _xor_value[y]) << '\n';
        }
        else {
            cin >> x >> y >> d;
            int tmp = _xor_value[x] ^ _xor_value[y];
            cout << int(tmp ^ d) << '\n';
        }
    }
}