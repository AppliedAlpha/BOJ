#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

/* ~= 13545, 13546
 * Sqrt Decomposition, Mo's Algorithm
 */

int n, m, k, sqrtn, a, b;
int ans[100003], v[100003], s[100003], cnt[1000003], bucket[500];
list<int> visited[1000003];

struct seg {
    int idx, s, e;

    bool operator < (seg &x) {
        if (s / sqrtn != x.s / sqrtn) return s / sqrtn < x.s / sqrtn;
        return e < x.e;
    }
};
vector<seg> query;


void query_add(int x) {
    if (visited[s[x]].size() >= 2) {
        int d = visited[s[x]].back() - visited[s[x]].front();
        cnt[d]--;
        bucket[d / sqrtn]--;
    }
    if (visited[s[x]].empty() || visited[s[x]].back() < x) visited[s[x]].push_back(x);
    else visited[s[x]].push_front(x);
    if (visited[s[x]].size() >= 2) {
        int d = visited[s[x]].back() - visited[s[x]].front();
        cnt[d]++;
        bucket[d / sqrtn]++;
    }
}

void query_sub(int x) {
    if (visited[s[x]].size() >= 2) {
        int d = visited[s[x]].back() - visited[s[x]].front();
        cnt[d]--;
        bucket[d / sqrtn]--;
    }
    if (visited[s[x]].back() == x) visited[s[x]].pop_back();
    else visited[s[x]].pop_front();
    if (visited[s[x]].size() >= 2) {
        int d = visited[s[x]].back() - visited[s[x]].front();
        cnt[d]++;
        bucket[d / sqrtn]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    sqrtn = sqrt(n);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        v[i] %= k;
        s[i] = (s[i-1] + v[i]) % k;
        // s[i] = (v[1] + v[2] + ... v[i]) % k
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        query.push_back({i, a, b});
    }
    sort(query.begin(), query.end());

    query_add(1);
    int rs = 1, re = 1;
    cnt[0] = bucket[0] = 2*k;

    for (int i=0; i<m; i++) {
        seg q = query[i];
        int qs = --q.s, qe = q.e, qi = q.idx;
        while (rs > qs) query_add(--rs);
        while (re < qe) query_add(++re);
        while (rs < qs) query_sub(rs++);
        while (re > qe) query_sub(re--);

        int p = (n+1)/sqrtn;
        while (!bucket[p]) p--;
        int x = min(n, (p+1)*sqrtn);
        while (!cnt[x]) x--;

        ans[qi] = x;
    }

    for (int i=0; i<m; i++) cout << ans[i] << '\n';

    return 0;
}