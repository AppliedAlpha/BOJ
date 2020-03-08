#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int solve() {
    int n, m, tmp, k = 0;
    priority_queue<int> pq;
    queue<pii> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        q.push({tmp, i});
        pq.push(tmp);
    }
    while (!q.empty()) {
        int imp = q.front().first;
        int idx = q.front().second;
        q.pop();
        if (pq.top() == imp) {
            k++;
            pq.pop();
            if (idx == m) break;
        }
        else q.push({imp, idx});
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) cout << solve() << '\n';
    return 0;
}
