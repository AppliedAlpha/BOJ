#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, sqrtn, a, b;
int ans[500003] = {0, }, v[500003] = {0, };
int visited[500003] = {0, }; // visited[i] = count i in range
int all_c[500003] = {0, }; // all_c[i] = count "count = i"

struct seg {
    int idx, s, e;

    bool operator < (seg &x) {
        if (s / sqrtn != x.s / sqrtn) return s / sqrtn < x.s / sqrtn;
        return e < x.e;
    }
};
vector<seg> query;

/* ~= 13548
   I Don't Know Why Is It Working
   Condition: "... N natural integers less than '1,000,000,000"?
   REALLY?
*/

void query_add(int x) {
    x = v[x];
    all_c[visited[x]]--;
    visited[x]++;
    all_c[visited[x]]++;
}

void query_sub(int x) {
    x = v[x];
    all_c[visited[x]]--;
    visited[x]--;
    all_c[visited[x]]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    sqrtn = sqrt(n);
    for (int i=1; i<=n; i++) cin >> v[i];
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
        ans[qi] = all_c[2];
    }

    for (int i=0; i<m; i++) cout << ans[i] << '\n';

    return 0;
}