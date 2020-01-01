#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << 'A';
    }
    else if (n == 2) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << a;
        else cout << 'A';
    }
    else {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int p = 0, q, dx, dy; // y=px+q
        dx = v[1] - v[0];
        dy = v[2] - v[1];
        if (dx) p = dy / dx;
        q = v[1] - p * v[0];
        bool check = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] * p + q != v[i + 1]) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << v.back() * p + q;
        } else cout << 'B';
    }
}