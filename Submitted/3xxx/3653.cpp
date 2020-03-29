#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, k, t, r, temp;
vector<int> seg(800008, 0), v(200002, 0);

// TRY
int update(int i, int x, int idx, int st, int en) {
    if (i < st || i > en) return seg[idx];
    if (st == en) return seg[idx] = x;
    int mid = (st + en) / 2;
    return seg[idx] = update(i, x, 2 * idx, st, mid) + update(i, x, 2 * idx + 1, mid + 1, en);
}

int query(int i, int j, int idx, int st, int en) {
    if (j < st || i > en) return 0;
    if (i <= st && j >= en) return seg[idx];
    int mid = (st + en) / 2;
    return query(i, j, 2 * idx, st, mid) + query(i, j, 2 * idx + 1, mid + 1, en);
}

int update(int i, int x) { return update(i, x, 1, 1, n+m); }

int query(int i, int j) { return query(i, j, 1, 1, n+m); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        seg.clear();
        v.clear();
        cin >> n >> m;
        seg.resize(800008);
        v.resize(200002);
        k = m+1;
        for (int i=k; i<=n+m; i++) { // 초기 업데이트
            update(i, 1);
            v[i-m] = i;
        }
        k = r = m;
        while (r--) { // 영화를 본다!
            cin >> temp;
            cout << query(1, v[temp] - 1) << ' ';
            update(v[temp], 0);
            v[temp] = k--;
            update(v[temp], 1);
        }
        cout << '\n';
    }
    return 0;
}