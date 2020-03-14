#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

int n, m, k, sqrtn, a, b;
int ans[100003] = {0, }, v[100003] = {0, }, cnt[100003] = {1, }, sqd[500] = {1, };
list<int> visited[100003];

struct seg {
    int idx, s, e;

    bool operator < (seg &x) {
        if (s / sqrtn != x.s / sqrtn) return s / sqrtn < x.s / sqrtn;
        return e < x.e;
    }
};
vector<seg> query;


void query_add(int x) {
    if (visited[v[x]].size() >= 2) {
        int d = visited[v[x]].back() - visited[v[x]].front();
        cnt[d]--;
        sqd[d / sqrtn]--;
    }
    if (visited[v[x]].empty() || visited[v[x]].back() < x) visited[v[x]].push_back(x);
    else visited[v[x]].push_front(x);
    if (visited[v[x]].size() >= 2) {
        int d = visited[v[x]].back() - visited[v[x]].front();
        cnt[d]++;
        sqd[d / sqrtn]++;
    }
}

void query_sub(int x) {
    if (visited[v[x]].size() >= 2) {
        int d = visited[v[x]].back() - visited[v[x]].front();
        cnt[d]--;
        sqd[d / sqrtn]--;
    }
    if (visited[v[x]].back() == x) visited[v[x]].pop_back();
    else visited[v[x]].pop_front();
    if (visited[v[x]].size() >= 2) {
        int d = visited[v[x]].back() - visited[v[x]].front();
        cnt[d]++;
        sqd[d / sqrtn]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
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

        int p = (n+1)/sqrtn;
        while (!sqd[p]) p--;
        int x = min(n, (p+1)*sqrtn);
        while (!cnt[x]) x--;

        ans[qi] = x;
    }

    for (int i=0; i<m; i++) cout << ans[i] << '\n';

    return 0;
}