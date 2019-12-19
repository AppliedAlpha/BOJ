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