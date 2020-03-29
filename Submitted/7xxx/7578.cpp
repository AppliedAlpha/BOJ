#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll res = 0;
int seg[500001], n, temp;
map<int, int> m;

// Binary Indexed Tree (From 1280.cpp)
// TRY

void update(int i, int x) {
    while (i <= n) {
        seg[i] += x;
        i += (i & -i);
    }
}

ll query(int i) {
    ll sum = 0;
    while (i >= 1) {
        sum += seg[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        m[temp] = i;
        // m[temp] = temp의 A 위치
    }
    for (int i=1; i<=n; i++) {
        cin >> temp;
        res += (i-1) - query(m[temp]);
        update(m[temp], 1);
        // m[temp] (temp A 위치) 값이 한 번 들어옴
    }
    cout << res;
    return 0;
}