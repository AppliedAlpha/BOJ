#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000003], n, m, a, b, c;

// Set을 사용해보는 건 어떨까

int _get(int x) {
    if (parent[x] == x) return x;
    return parent[x] = _get(parent[x]);
}

void _union(int x, int y) {
    x = _get(x);
    y = _get(y);
    if (x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<=n; i++) parent[i] = i;
    while (m--) {
        cin >> a >> b >> c;
        if (a) cout << (_get(b) == _get(c) ? "YES" : "NO") << '\n';
        else _union(b, c);
    }
    return 0;
}
