#include <iostream>
using namespace std;
typedef long long ll;
ll a[1000003] = {0, }, cnt[1000003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp;
    ll res = 0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        a[i] = (a[i-1] + tmp) % m;
        if (!a[i]) res++;
        cnt[a[i]]++;
    }
    for (int i=0; i<m; i++) {
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << res;
}