#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> visited;
vector<vector<int>> adj;

int bfs(int start, int end) {
    int dist = 0;
    if (start == end) return 0;
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        dist = visited[n] + 1;
        for (auto u : adj[n]) {
            if (visited[u] == -1) {
                q.push(u);
                visited[u] = dist;
            }
        }
    }
    return visited[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, start, end, m;
    cin >> n >> start >> end >> m;
    visited.resize(n+1);
    adj.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(visited.begin(), visited.end(), -1);
    for (auto i : adj) sort(i.begin(), i.end());
    cout << bfs(start, end);
    return 0;
}