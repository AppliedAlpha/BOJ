#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, sqrtn, a, b, res = 0;
int ans[100003] = {0, }, v[100003] = {0, };
int visited[1000003] = {0, }; // visited[i] = count i in range

struct seg {
    int idx, s, e;

    bool operator < (seg &x) {
        if (s / sqrtn != x.s / sqrtn) return s / sqrtn < x.s / sqrtn;
        return e < x.e;
    }
};
vector<seg> query;

// ~= 13548
void query_add(int x) {
    x = v[x];
    if (!visited[x]) res++;
    visited[x]++;
}

void query_sub(int x) {
    x = v[x];
    if (visited[x] == 1) res--;
    visited[x]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    sqrtn = sqrt(n);
    for (int i=1; i<=n; i++) cin >> v[i];
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        query.push_back({i, a, b});
    }
    sort(query.begin(), query.end());

    query_add(1);
    int rs = 1, re = 1;

    for (int i=0; i<m; i++) {
        seg q = query[i];
        int qs = q.s, qe = q.e, qi = q.idx;
        while (rs > qs) query_add(--rs);
        while (re < qe) query_add(++re);
        while (rs < qs) query_sub(rs++);
        while (re > qe) query_sub(re--);
        ans[qi] = res;
    }

    for (int i=0; i<m; i++) cout << ans[i] << '\n';

    return 0;
}