#include <iostream>
using namespace std;
int a[100003] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp, start, end;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }
    cin >> m;
    while (m--) {
        cin >> start >> end;
        cout << a[end] - a[start - 1] << '\n';
    }
}