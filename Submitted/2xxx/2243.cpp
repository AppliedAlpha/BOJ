#include <iostream>
#define size 4000004
using namespace std;
typedef long long ll;
int n, a, b;
ll seg[size] = {0LL, }, res, c;

// TRY ?
void update(int i, ll x, int idx, int st, int en) {
    if (i < st || i > en) return;
    seg[idx] += x;
    if (st != en) {
        int mid = (st + en) / 2;
        update(i, x, 2 * idx, st, mid);
        update(i, x, 2 * idx + 1, mid + 1, en);
    }
}

ll query(int idx, int st, int en, int k) {
    if ((st == en) && !res) {
        cout << st << '\n';
        return st;
    }
    // searching
    // left >= k : left
    if (!res && (idx * 2 <= size && seg[idx * 2] >= k)) {
        return res = query(idx * 2, st, (st + en) / 2, k);
    }
    k -= seg[idx * 2];
    // else right: k - left
    if (!res && (idx * 2 + 1 <= size && seg[idx * 2 + 1] >= k)) {
        return res = query(idx * 2 + 1, (st + en) / 2 + 1, en, k);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            int idx = query(1, 0, 1000000, b);
            res = 0LL;
            update(idx, -1, 1, 0, 1000000);
        }
        else {
            cin >> b >> c;
            update(b, c, 1, 0, 1000000);
        }
    }
    return 0;
}