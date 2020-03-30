#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b, c, cur = 0;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    v.resize(n);
    for (auto & i : v) cin >> i; // [0, n)
    while (m--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            v[((b-1)+cur) % n] += c;
        }
        else if (a == 2) {
            cin >> b;
            cur = (cur - b + n) % n;
        }
        else {
            cin >> b;
            cur = (cur + b) % n;
        }
    }
    for (int i=0; i<n; i++) cout << v[(i + cur) % n] << ' ';
    return 0;
}