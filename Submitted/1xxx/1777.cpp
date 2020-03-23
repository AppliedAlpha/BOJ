#include <iostream>
using namespace std;
int n, a, seg[400004], arr[100002], input[100002];

// ~= 1849
int update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2 * idx, st, mid) + update(i, x, 2 * idx + 1, mid + 1, en);
}

int query(int val, int idx, int st, int en) {
    if (st == en) return st;
    int mid = (st + en) / 2;
    if (seg[2 * idx] >= val) return query(val, 2 * idx, st, mid);
    return query(val - seg[2 * idx], 2 * idx + 1, mid + 1, en);
}

int update(int i, int x) { return update(i, x, 1, 1, n); }

int query(int i) { return query(i, 1, 1, n); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) update(i, 1);
    for (int i=1; i<=n; i++) cin >> input[i];
    for (int i=n; i>=1; i--) {
        int tmp = query(input[i]+1);
        arr[tmp] = i;
        update(tmp, 0);
    }
    for (int i=n; i>=1; i--) cout << arr[i] << ' ';
    return 0;
}