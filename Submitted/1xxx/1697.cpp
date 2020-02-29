#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<int> visited(100002);

int bfs(int st, int en) {
    queue<pii> q;
    q.push({st, 0});
    visited[st] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == en) return now.second;
        vector<int> tmp = {now.first * 2, now.first + 1, now.first - 1};
        for (auto i : tmp) {
            if (i >= 0 && i <= 100000) {
                if (!visited[i]) {
                    q.push({i, now.second + 1});
                    visited[i] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int st, en;
    cin >> st >> en;
    cout << bfs(st, en);
    return 0;
}


/* (19.11.26)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct state {
    int x, cnt;
};

bool visited[200001];
vector<state> adj[200001];
queue<state> q;

int solve(int n, int k) {
    if (n >= k) return n-k;
    visited[n] = true;
    q.push({n, 0});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (!visited[s.x-1] && s.x-1 >= 0) adj[s.x].push_back({s.x-1, s.cnt});
        if (!visited[s.x+1]) adj[s.x].push_back({s.x+1, s.cnt});
        if (!visited[s.x*2] && s.x*2 <= k+1) adj[s.x].push_back({s.x*2, s.cnt});
        for (auto u : adj[s.x]) {
            if (u.x == k) return ++u.cnt;
            if (visited[u.x]) continue;
            visited[u.x] = true;
            q.push({u.x, ++u.cnt});
            //cout << u.x << " | " << u.cnt << '\n';
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
}
 */